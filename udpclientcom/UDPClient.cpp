// UDPClient.cpp : Implementation of CUDPClient
#include "stdafx.h"
#include "udpclientcom.h"
#include "UDPClient.h"

/////////////////////////////////////////////////////////////////////////////
// CUDPClient

// _open file handling
#include "io.h"
#include <fcntl.h>

//bstr
#include <comdef.h>

// _stat
#include "sys\stat.h"

// wnet*
//Header: Declared in winnetwk.h.
//Import Library: Use mpr.lib.

//
#include "Log.h"

//
const char *description = "Intrafoundation.UDPClient.2";
const char *copyright =
		"Copyright (c) 2000, 2001, 2003, 2004, 2012 by Lewis Sellers. <a href=\"http://www.intrafoundation.com\">http://www.intrafoundation.com</a>";
const char *version = "2.2, August 30th 2012";

//
int CUDPClient::m_last_instance = 0;

/////////////////////////////////////////////////////////////////////////////
//
//
CUDPClient::CUDPClient() {
	m_instance = ++m_last_instance;

	w = NULL;
	m_packet = new char[MAX_PACKET_SIZE + 1];
}

CUDPClient::~CUDPClient() {
	delete[] m_packet;
	m_packet = NULL;
}

/////////////////////////////////////////////////////////////////////////////
//
//

long CUDPClient::size_t_to_long(size_t t) {
	long l = (long) t;
	return l;
}

size_t CUDPClient::long_to_size_t(long l) {
	size_t t = (size_t) l;
	return t;
}

/////////////////////////////////////////////////////////////////////////////
//
//

/*
 */STDMETHODIMP CUDPClient::Open(BSTR strip, BSTR strport, long *bconnected) {
	//
	*bconnected = 0L;

	//
	if (m_packet == NULL)
		log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::Open",
				L"New packet failed. Can not open.");
	else {
		//
		memset(m_packet, 0, MAX_PACKET_SIZE);
		m_packetposition = 0L;
		m_packetlength = 0L;

		//
		if (w) {
			delete w;
			w = NULL;

			log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::Open",
					L"Already open.");
		} else {
			//
			char ip[MAX_IPEXPANSION + 1];
			char port[MAX_PORTEXPANSION + 1];

			size_t const minip = min(wcslen(strip) + 1, MAX_IPEXPANSION);
			size_t const minport = min(wcslen(strport) + 1, MAX_PORTEXPANSION);
			wcstombs(ip, strip, minip);
			wcstombs(port, strport, minport);
			w = new udp((char* const ) ip, (char* const ) port);
			if (w) {
				if (w->is_connected() == true)
					*bconnected = 1L; //TRUE;
				else {
					log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::Open",
							L"Low-level udp class is_connected (%s) failed on host %S:%S.",
							w->is_connected() ? L"true" : L"false", ip, port);

					delete w;
					w = NULL;
				}
			} else {
				log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::Open",
						L"Low-level udp class could not open connection to host %S:%S.",
						ip, port);
			}
		}
	}

	return S_OK ;
}

/////////////////////////////////////////////////////////////////////////////
//
//

/*
 */STDMETHODIMP CUDPClient::Close() {
	if (w) {
		delete w;
		w = NULL;
	} else
		log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::Close",
				L"Already closed.");

	return S_OK ;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//
//

/*
 */STDMETHODIMP CUDPClient::Send(BSTR strText, long* bytes) {
	HRESULT retval = S_OK;

	if (w) {
		if (strText != NULL) {
			const size_t clength = wcslen(strText);
			char *pszstr = new char[clength];
			if (pszstr) {
				wcstombs(pszstr, strText, clength);

				*bytes = size_t_to_long(w->Send(pszstr, clength));

				delete[] pszstr;
				pszstr = NULL;
			}
		} else
			retval = E_POINTER;
	} else
		*bytes = 0L;

	return retval;
}

/*
 */STDMETHODIMP CUDPClient::Recv(BSTR* pstrText) {
	HRESULT retval = S_OK;

	if (w) {
		char* buf = NULL;
		const size_t length = w->Recv(buf);
		if (buf) {
			if (length > 0) {
				//new bstr section to get around iis5's 256kb stack limit
				BSTR wbuf = new wchar_t[length + 1];
				if (wbuf) {
					mbstowcs(wbuf, buf, length + 1);
					*pstrText = SysAllocString(wbuf);
					delete[] wbuf;
					wbuf = NULL;
				} else
					log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::Recv",
							L"Memory allocation of %d bytes failed.",
							(length + 1) * 2);
			} else
				*pstrText = SysAllocString(L"");

			//
			delete[] buf;
			buf = NULL;
		} else
			log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::Recv",
					L"Recv failed to obtain data from the socket.");
	} else
		*pstrText = SysAllocString(L"");

	return retval;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//
//

/*
 */STDMETHODIMP CUDPClient::SendCSV(BSTR strText, long* bytes) {
	HRESULT retval = S_OK;

	if (w) {
		if (strText != NULL) {
			//
			const size_t clength = wcslen(strText) + 1;
			char *csv = new char[clength];
			if (csv) {
				wcstombs(csv, strText, clength);

				//
				char *decsv = new char[clength];
				if (decsv == NULL) {
					log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::SendCSV",
							L"Memory allocation of %d bytes failed.", clength);
					retval = E_OUTOFMEMORY;
				} else {
					//
					char *s = csv;
					char *d = decsv;
					int count = 0;
					char *c = NULL;
					do {
						int i = atoi(s);
						*d = (BYTE) i;
						d++;
						char *c = strchr(s, ',');
						if (c)
							s += (c - s);
						count++;
					} while (c != NULL);

					*bytes = size_t_to_long(w->Send(decsv, count));

					//
					delete[] decsv;
					decsv = NULL;
				}

				//
				delete[] csv;
				csv = NULL;
			}
		} else
			retval = E_POINTER;
	} else
		*bytes = 0L;

	return retval;
}

/*
 */STDMETHODIMP CUDPClient::RecvCSV(BSTR* pstrText) {
	HRESULT retval = S_OK;

	size_t buflength = 0;

	if (w) {
		// get data
		char* buf = NULL;
		buflength = w->Recv(buf);

		if (buf) {
			// decode raw data to csv
			if (buflength > 0) {
				//
				const size_t newbuflength = buflength * 4;
				char* newbuf = new char[newbuflength];
				newbuf[0] = '\0';

				char* s = buf;
				for (size_t i = 0; i < buflength; i++) {
					char tmp[MAX_DWORDEXPANSION];
					_itoa((BYTE) * s, tmp, 10);
					if (i != 0)
						strcat(newbuf, ",");
					strcat(newbuf, tmp);
					s++;
				}

				//new bstr section to get around iis5's 256kb stack limit
				BSTR wbuf = new wchar_t[newbuflength + 1];
				if (wbuf) {
					mbstowcs(wbuf, newbuf, newbuflength + 1);
					*pstrText = SysAllocString(wbuf);
					delete[] wbuf;
					wbuf = NULL;
				} else
					log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::RecvCSV",
							L"Memory allocation of %d bytes failed.",
							(newbuflength + 1) * 2);

				//
				delete[] newbuf;
				newbuf = NULL;
			}

			//
			delete[] buf;
			buf = NULL;
		} else
			log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::Recv",
					L"Recv failed to obtain data from the socket.");
	}

	//
	if (buflength <= 0L)
		*pstrText = SysAllocString(L"");

	return retval;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
//
//

/*
 */STDMETHODIMP CUDPClient::SendPacket(long* bytes) {
	if (!w)
		*bytes = 0L;
	else
		*bytes = size_t_to_long(w->Send(m_packet, m_packetlength));

	return (HRESULT)S_OK;
}

/*
 */STDMETHODIMP CUDPClient::RecvPacket(long *bytes) {
	HRESULT retval = S_OK;

	if (!w) {
		memset(m_packet, 0, m_packetlength);
		m_packetposition = 0L;
	} else {
		m_packetlength = w->Recv(m_packet);
		if (m_packetlength < 0L)
			m_packetlength = 0L;
		m_packetposition = 0L;
	}

	*bytes = size_t_to_long(m_packetlength);

	return (HRESULT)S_OK;
}

/*
 */STDMETHODIMP CUDPClient::packetclear() {
	memset(m_packet, 0, MAX_PACKET_SIZE);
	m_packetposition = 0L;
	m_packetlength = 0L;

	return (HRESULT)S_OK;
}

/*
 */STDMETHODIMP CUDPClient::get_packetEOF(long* pbool) {
	if (!w)
		*pbool = 1L;
	else
		*pbool = (m_packetposition <= m_packetlength) ? 1L : 0L;

	return (HRESULT)S_OK;
}

/*
 */STDMETHODIMP CUDPClient::get_packetlength(long* bytes) {
	if (!w)
		*bytes = 0L;
	else
		*bytes = size_t_to_long(m_packetlength);

	return (HRESULT)S_OK;
}

/*
 */STDMETHODIMP CUDPClient::get_packetposition(long* bytes) {
	if (!w)
		*bytes = 0L;
	else
		*bytes = size_t_to_long(m_packetposition);

	return (HRESULT)S_OK;
}

/*
 */STDMETHODIMP CUDPClient::put_packetreposition(long bytes) {
	if (bytes < 0L)
		m_packetposition = 0L;
	else if (m_packetposition > m_packetlength)
		m_packetposition = m_packetlength;
	else
		m_packetposition = long_to_size_t(bytes);

	return (HRESULT)S_OK;
}

/*
 */STDMETHODIMP CUDPClient::addpacketnumber(BSTR strType, double val) {
	int so, casttype;

	if (wcscmp(strType, L"BYTE") == 0) {
		so = sizeof(BYTE);
		casttype = 1;
	} else if (wcscmp(strType, L"WORD") == 0) {
		so = sizeof(WORD);
		casttype = 2;
	} else if (wcscmp(strType, L"DWORD") == 0) {
		so = sizeof(DWORD);
		casttype = 3;
	} else if (wcscmp(strType, L"int8") == 0) {
		so = sizeof(__int8);
		casttype = 4;
	} else if (wcscmp(strType, L"int16") == 0) {
		so = sizeof(__int16);
		casttype = 5;
	} else if (wcscmp(strType, L"int32") == 0) {
		so = sizeof(__int32);
		casttype = 6;
	} else if (wcscmp(strType, L"float32") == 0) {
		so = sizeof(float);
		casttype = 7;
	} else if (wcscmp(strType, L"float64") == 0) {
		so = sizeof(double);
		casttype = 8;
	} else {
		so = 0;
		casttype = 0;

		log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::addpacketnumber",
				L"Unknown number type %S (so=%d casttype=%d).", strType, so,
				casttype);
	}

	if (m_packetlength + so <= MAX_PACKET_SIZE) {
		switch (casttype) {
		case 1:
			*(BYTE *) (m_packet + m_packetlength) = (BYTE) val;
			break;
		case 2:
			*(WORD *) (m_packet + m_packetlength) = (WORD) val;
			break;
		case 3:
			*(DWORD *) (m_packet + m_packetlength) = (DWORD) val;
			break;
		case 4:
			*(__int8 *) (m_packet + m_packetlength) = (__int8) val;
			break;
		case 5:
			*(__int16 *) (m_packet + m_packetlength) = (__int16) val;
			break;
		case 6:
			*(__int32 *) (m_packet + m_packetlength) = (__int32) val;
			break;
		case 7:
			*(float *) (m_packet + m_packetlength) = (float) val;
			break;
		case 8:
			*(double *) (m_packet + m_packetlength) = (double) val;
			break;
		}
		m_packetlength += so;
	} else {
		log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::addpacketnumber",
				L"Attempt to exceed packet length of %d by %d.", m_packetlength,
				((m_packetlength + so) - m_packetlength));
	}

	return (HRESULT)S_OK;
}

/*
 */STDMETHODIMP CUDPClient::addpacketipport(BSTR strIP, int Port) {
	int const so = sizeof(ip4port);
	if (m_packetlength + so <= MAX_PACKET_SIZE) {
		char *s = (m_packet + m_packetlength);

		ip4port i4p;
		memset(&i4p, 0, sizeof(ip4port));

		size_t const clength = wcslen(strIP);
		char *pszstr = new char[clength];
		if (pszstr) {
			//
			wcstombs(pszstr, strIP, clength);

			// octets
			char *p = pszstr;
			for (int i = 0; i <= 3; i++) {
				int o = atoi(p);
				i4p.octet[i] = (BYTE) o;
				char *c = strchr(s, ',');
				if (c)
					s += (c - s);
				else
					break;
			}

			// port
			i4p.port = Port;

			//
			memcpy(s, &i4p, sizeof(ip4port)); //*(ip4port *)s=i4p;

			//
			m_packetlength += so;
		}
	} else {
		log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::addpacketipport",
				L"Attempt to exceed packet length of %d by %d.", m_packetlength,
				((m_packetlength + so) - m_packetlength));
	}

	return (HRESULT)S_OK;
}

/*
 */STDMETHODIMP CUDPClient::addpacketchar(BSTR str) {
	size_t const buflength = wcslen(str) + 1;
	char *buf = new char[buflength];
	if (buf) {
		wcstombs(buf, str, buflength);

		int const so = sizeof(char);

		if (m_packetlength + so <= MAX_PACKET_SIZE) {
			m_packet[m_packetlength] = (char) buf[0];
			m_packetlength += so;
		} else {
			log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::addpacketchar",
					L"Attempt to exceed packet length of %d by %d.",
					m_packetlength, ((m_packetlength + so) - m_packetlength));
		}

		delete[] buf;
		buf = NULL;
	}

	return (HRESULT)S_OK;
}

/*
 */STDMETHODIMP CUDPClient::addpacketstring(BSTR val) {
	size_t const buflength = wcslen(val) + 1;
	//int buflength=::SysStringLen(val); //v1.16
	char *buf = new char[buflength];
	if (buf) {
		wcstombs(buf, val, buflength);

		//int so=strlen(buf);
		//int so=buflength;

		//if(packetlength+so<=MAX_PACKET_SIZE)
		if (m_packetlength + buflength <= MAX_PACKET_SIZE) {
			//			strcpy((packet+packetlength),buf);
			//			packetlength+=so;
			memcpy((m_packet + m_packetlength), buf, buflength);
			m_packetlength += buflength;
		} else
			log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::addpacketstring",
					L"Attempt to exceed packet length of %d by %d.",
					m_packetlength,
					((m_packetlength + buflength) - m_packetlength));

		delete[] buf;
		buf = NULL;
	}

	return (HRESULT)S_OK;
}

/*
 */STDMETHODIMP CUDPClient::addpacketstringN(BSTR val) {
	//int len=wcslen(val);
	int const len = ::SysStringLen(val); //v1.16
	char *buf = new char[len + 1];
	if (buf) {
		wcstombs(buf, val, len);

		if (m_packetlength + len <= MAX_PACKET_SIZE) {
			memcpy((m_packet + m_packetlength), buf, len);
			//strncpy((packet+packetlength),buf,len);
			m_packetlength += len;
		} else
			log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::addpacktestringN",
					L"Attempt to exceed packet length of %ld by %ld.",
					m_packetposition,
					((m_packetposition + m_packetlength) - m_packetposition));

		delete[] buf;
		buf = NULL;
	}

	return (HRESULT)S_OK;
}

/*
 */STDMETHODIMP CUDPClient::packetnumber(BSTR strType, double* val) {
	int so, casttype;

	if (wcscmp(strType, L"BYTE") == 0) {
		so = sizeof(BYTE);
		casttype = 1;
	} else if (wcscmp(strType, L"WORD") == 0) {
		so = sizeof(WORD);
		casttype = 2;
	} else if (wcscmp(strType, L"DWORD") == 0) {
		so = sizeof(DWORD);
		casttype = 3;
	} else if (wcscmp(strType, L"int8") == 0) {
		so = sizeof(__int8);
		casttype = 4;
	} else if (wcscmp(strType, L"int16") == 0) {
		so = sizeof(__int16);
		casttype = 5;
	} else if (wcscmp(strType, L"int32") == 0) {
		so = sizeof(__int32);
		casttype = 6;
	} else if (wcscmp(strType, L"float32") == 0) {
		so = sizeof(float);
		casttype = 7;
	} else if (wcscmp(strType, L"float64") == 0) {
		so = sizeof(double);
		casttype = 8;
	} else {
		so = 0;
		casttype = 0;

		log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::packetnumber",
				L"Unknown number type %S (so=%d casttype=%d).", strType, so,
				casttype);
	}

	char *s = m_packet + m_packetposition;
	if (m_packetposition + so <= m_packetlength) {
		double tmp;
		switch (casttype) {
		case 1:
			tmp = *(BYTE *) s;
			break;
		case 2:
			tmp = *(WORD *) s;
			break;
		case 3:
			tmp = *(DWORD *) s;
			break;
		case 4:
			tmp = *(__int8 *) s;
			break;
		case 5:
			tmp = *(__int16 *) s;
			break;
		case 6:
			tmp = *(__int32 *) s;
			break;
		case 7:
			tmp = *(float *) s;
			break;
		case 8:
			tmp = *(double *) s;
			break;
		default:
			tmp = 0.0;
		}
		*val = tmp;

		m_packetposition += so;
	} else {
		*val = (double) 0.0;

		log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::addpacketnumber",
				L"Attempt to exceed packet length of %ld by %ld.",
				m_packetposition, ((m_packetposition + so) - m_packetposition));
	}

	return (HRESULT)S_OK;
}

/*
 */STDMETHODIMP CUDPClient::packetipport(BSTR* strIP, int* Port) {
	long const so = sizeof(ip4port);

	if (m_packetposition + so <= m_packetlength) {
		char *s = m_packet + m_packetposition;

		ip4port i4p;
		memcpy(&i4p, s, sizeof(ip4port));

		*Port = i4p.port;
		char tmp[16 + 4];
		_snprintf(tmp, 16, "%4d.%4d.%4d.%4d", i4p.octet[0], i4p.octet[1],
				i4p.octet[2], i4p.octet[3]);

		size_t const clength = strlen(tmp);
		BSTR wbuf = new wchar_t[clength + 1 + 1];
		if (wbuf) {
			mbstowcs(wbuf, tmp, clength + 1);
			*strIP = SysAllocString(wbuf);
			delete[] wbuf;
		}

		m_packetposition += so;
	} else {
		*strIP = SysAllocString(L"");
		*Port = 0;

		log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::packetipport",
				L"Attempt to exceed packet length of %d by %d.", m_packetlength,
				((m_packetlength + so) - m_packetlength));
	}

	return (HRESULT)S_OK;
}

/*
 */STDMETHODIMP CUDPClient::packetchar(BSTR* pstr) {
	long const so = sizeof(char);

	if (m_packetposition + so <= m_packetlength) {
		char *buf = new char[2];
		if (buf) {
			buf[0] = *(char *) (m_packet + m_packetposition);
			buf[1] = '\0';

			BSTR wbuf = new wchar_t[3];
			if (wbuf) {
				mbstowcs(wbuf, buf, 2);
				*pstr = SysAllocString(wbuf);
				delete[] wbuf;
				wbuf = NULL;
			}

			delete[] buf;
			buf = NULL;
		}

		m_packetposition += so;
	} else {
		*pstr = SysAllocString(L"");

		log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::packetchar",
				L"Attempt to exceed packet length of %d by %d.", m_packetlength,
				((m_packetlength + so) - m_packetlength));
	}

	return (HRESULT)S_OK;
}

/*
 */STDMETHODIMP CUDPClient::packetstring(BSTR* pstr) {
	size_t const so = strlen((m_packet + m_packetposition));

	if (m_packetposition + so <= m_packetlength) {
		char *buf = new char[so + 1];
		if (buf) {
			strncpy(buf, (m_packet + m_packetposition), so + 1);

			BSTR wbuf = new wchar_t[so + 2];
			if (wbuf) {
				mbstowcs(wbuf, buf, so + 1);
				*pstr = SysAllocString(wbuf);
				delete[] wbuf;
				wbuf = NULL;
			}

			delete[] buf;
			buf = NULL;

			m_packetposition += (so + 1L);
		}
	} else {
		*pstr = SysAllocString(L"");

		log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::packetstring",
				L"Attempt to exceed packet length of %d by %d.", m_packetlength,
				((m_packetlength + so) - m_packetlength));
	}

	return (HRESULT)S_OK;
}

STDMETHODIMP CUDPClient::packetstringN(long len, BSTR* pstr) {
	size_t tlen = long_to_size_t(len);
	if (m_packetposition + tlen <= m_packetlength) {
		char* buf = new char[tlen + 1];
		if (buf) {
			strncpy(buf, (m_packet + m_packetposition), tlen);
			buf[tlen] = '\0';

			BSTR wbuf = new wchar_t[tlen + 2L];
			if (wbuf) {
				mbstowcs(wbuf, buf, tlen + 1L);
				*pstr = SysAllocString(wbuf);
				delete[] wbuf;
				wbuf = NULL;
			}

			delete[] buf;
			buf = NULL;

			m_packetposition += len;
		}
	} else {
		*pstr = SysAllocString(L"");

		log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::packetstringN",
				L"Attempt to exceed packet length of %d by %d.", m_packetlength,
				((m_packetlength + len) - m_packetlength));
	}

	return (HRESULT)S_OK;
}

/*
 */STDMETHODIMP CUDPClient::packetstringC(BSTR c, BSTR* pstr) {
	// default character
	char ch = '\0';

	// get specified character in ch
	char *buf = new char[2];
	if (buf) {
		wcstombs(buf, c, 1);
		ch = buf[0];
		delete[] buf;
		buf = NULL;
	}

	// get length of string using special terminating character
	size_t len = 0;
	char *p = m_packet + m_packetposition;
	while ((m_packetposition + len) < m_packetlength) {
		if (*p == ch)
			break;
		p++;
		len++;
	}

	//
	if (m_packetposition + len <= m_packetlength) {
		char *buf = new char[len + 1];
		if (buf) {
			strncpy(buf, (m_packet + m_packetposition), len);
			buf[len] = '\0';

			BSTR wbuf = new wchar_t[len + 2];
			if (wbuf) {
				mbstowcs(wbuf, buf, len + 1);
				*pstr = SysAllocString(wbuf);
				delete[] wbuf;
				wbuf = NULL;
			}

			delete[] buf;
			buf = NULL;

			m_packetposition += (len + 1L);
		}
	} else {
		*pstr = SysAllocString(L"");

		log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::packetstringC",
				L"Attempt to exceed packet length of %d by %d.", m_packetlength,
				((m_packetlength + len) - m_packetlength));
	}

	return (HRESULT)S_OK;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//
//

/*
 */STDMETHODIMP CUDPClient::put_timeout(double seconds) {
	if (w) {
		long const s = (long) seconds;
		long const ms = (long) ((seconds - (double) s) * 1000);
		w->timeout(s, ms);
		return S_OK ;
	} else
		return S_OK ;
}

/*
 */STDMETHODIMP CUDPClient::get_timeout(double* pseconds) {
	if (w) {
		int s = 0;
		int ms = 0;
		w->get_timeout(s, ms);
		*pseconds = (double) s + ((double) ms / 1000.0);
		return S_OK ;
	} else {
		*pseconds = 0.0;
		return S_OK ;
	}
}

/////////////////////////////////////////////////////////////////////////////
//
//

/*
 */STDMETHODIMP CUDPClient::get_description(BSTR* pstr) {
	CComBSTR bstrtmp(description);
	if (!bstrtmp)
		return E_POINTER ;
	else {
		*pstr = bstrtmp.Detach();
		return S_OK ;
	}
}

/*
 */STDMETHODIMP CUDPClient::get_copyright(BSTR* pstr) {
	CComBSTR bstrtmp(copyright);
	if (!bstrtmp)
		return E_POINTER ;
	else {
		*pstr = bstrtmp.Detach();
		return S_OK ;
	}
}

/*
 */STDMETHODIMP CUDPClient::get_version(BSTR* pstr) {
	CComBSTR bstrtmp(version);
	if (!bstrtmp)
		return E_POINTER ;
	else {
		*pstr = bstrtmp.Detach();
		return S_OK ;
	}
}

/*
 */STDMETHODIMP CUDPClient::get_thread(long* pVal) {
	DWORD tid = GetCurrentThreadId();
	*pVal = (long) tid;
	return S_OK ;
}

/*
 */STDMETHODIMP CUDPClient::get_instance(long* pVal) {
	*pVal = (long) m_instance;
	return S_OK ;
}

/*
 */STDMETHODIMP CUDPClient::get_instances(long* pVal) {
	*pVal = (long) m_last_instance;
	return S_OK ;
}

/*
 */STDMETHODIMP CUDPClient::get_Log(BSTR* pstr) {
	CComBSTR bstrtmp(log.Logs());
	if (!bstrtmp)
		return E_OUTOFMEMORY ;
	else {
		*pstr = bstrtmp.Detach();
		return S_OK ;
	}
}

/*
 */STDMETHODIMP CUDPClient::ClearLog() {
	log.Clear();

	return S_OK ;
}

/////////////////////////////////////////////////////////////////////////////
//
//

/*
 */STDMETHODIMP CUDPClient::get_localaddress(BSTR* pstr) {
	//
	if (!w)
		*pstr = SysAllocString(L"");
	else {
		char *lip = NULL;
		int lport = 0;
		char *rip = NULL;
		int rport = 0;
		w->endpoints(lip, lport, rip, rport);

		char *buf = new char[MAX_ADDRESS + 2];
		if (buf == NULL) {
			log.AddLog(_T(__FILE__), __LINE__, L"CUDPClient::get_localaddress",
					L"Memory allocation of %d bytes failed.",
					MAX_ADDRESS + 2);
		} else {
			memset(buf, 0, MAX_ADDRESS);
			sprintf(buf, "%s:%d", lip, lport);
			size_t const buflength = strlen(buf);

			if (buflength == 0)
				*pstr = SysAllocString(L"");
			else {
				BSTR wbuf = new wchar_t[buflength + 2];
				if (wbuf) {
					mbstowcs(wbuf, buf, buflength + 1);
					*pstr = SysAllocString(wbuf);
					delete[] wbuf;
					wbuf = NULL;
				}
			}

			delete[] buf;
			buf = NULL;
		}
	}

	return S_OK ;
}

/*
 */STDMETHODIMP CUDPClient::get_remoteaddress(BSTR* pstr) {
	//
	if (!w)
		*pstr = SysAllocString(L"");
	else {
		char *lip = NULL;
		int lport = 0;
		char *rip = NULL;
		int rport = 0;
		w->endpoints(lip, lport, rip, rport);

		char *buf = new char[MAX_ADDRESS + 2];

		memset(buf, 0, MAX_ADDRESS);
		sprintf(buf, "%s:%d", rip, rport);
		const size_t buflength = strlen(buf);

		if (buflength == 0)
			*pstr = SysAllocString(L"");
		else {
			BSTR wbuf = new wchar_t[buflength + 2];
			if (wbuf) {
				mbstowcs(wbuf, buf, buflength + 1);
				*pstr = SysAllocString(wbuf);
				delete[] wbuf;
				wbuf = NULL;
			}
		}

		delete[] buf;
		buf = NULL;
	}

	return S_OK ;
}

/////////////////////////////////////////////////////////////////////////////
//
//

/*
 */STDMETHODIMP CUDPClient::get_sendlength(long* pbytes) {
	if (w) {
		size_t s, r, b, m;
		w->bufferlengths(s, r, b, m);
		*pbytes = size_t_to_long(s);
	} else
		*pbytes = 0L;

	return S_OK ;
}

/*
 */STDMETHODIMP CUDPClient::get_recvlength(long* pbytes) {
	if (w) {
		size_t s, r, b, m;
		w->bufferlengths(s, r, b, m);
		*pbytes = size_t_to_long(r);
	} else
		*pbytes = 0L;

	return S_OK ;
}

/*
 */STDMETHODIMP CUDPClient::get_buffersize(long* pbytes) {
	if (w) {
		size_t s, r, b, m;
		w->bufferlengths(s, r, b, m);
		*pbytes = size_t_to_long(b);
	} else
		*pbytes = 0L;

	return S_OK ;
}

/*
 */STDMETHODIMP CUDPClient::get_messagelength(long* pbytes) {
	if (w) {
		size_t s, r, b, m;
		w->bufferlengths(s, r, b, m);
		*pbytes = size_t_to_long(m);
	} else
		*pbytes = 0L;

	return S_OK ;
}

/////////////////////////////////////////////////////////////////////////////
//
//

/*
 */STDMETHODIMP CUDPClient::get_udpsocket(long* pVal) {
	if (w) { //SOCKET UINT to long
		*pVal = (long) w->udpsocket();
		return S_OK ;
	} else {
		*pVal = 0L;
		return S_OK ;
	}
}

/*
 */STDMETHODIMP CUDPClient::get_bytessent(long* pVal) {
	if (w) {
		size_t bs, br;
		w->bytestransferred(bs, br);
		*pVal = size_t_to_long(bs);
		return S_OK ;
	} else {
		*pVal = 0L;
		return S_OK ;
	}
}

/*
 */STDMETHODIMP CUDPClient::get_bytesreceived(long* pVal) {
	if (w) {
		size_t bs, br;
		w->bytestransferred(bs, br);
		*pVal = size_t_to_long(br);
		return S_OK ;
	} else {
		*pVal = 0L;
		return S_OK ;
	}
}

// obsolete
STDMETHODIMP CUDPClient::get_senttimeout(double* pVal) {

	*pVal = (double) 0.0;
	return S_OK ;
}

// obsolete
STDMETHODIMP CUDPClient::get_receivedtimeout(double* pVal) {
	*pVal = (double) 0.0;
	return S_OK ;
}

/*
 */STDMETHODIMP CUDPClient::get_kbpssending(double* pVal) {
	if (w)
		*pVal = w->kbps_sending();
	else
		*pVal = (double) 0.0;

	return S_OK ;
}

/*
 */STDMETHODIMP CUDPClient::get_kbpsreceiving(double* pVal) {
	if (w)
		*pVal = w->kbps_receiving();
	else
		*pVal = (double) 0.0;

	return S_OK ;
}

/*
 */STDMETHODIMP CUDPClient::get_ping(long* pVal) {
	if (w)
		*pVal = size_t_to_long(w->ping());
	else
		*pVal = 0L;

	return S_OK ;
}

/*
 */STDMETHODIMP CUDPClient::get_is_connected(long* pstatus) {
	if (w)
		*pstatus = (long) w->is_connected();
	else
		*pstatus = FALSE;
	return S_OK ;
}
