// UDPClient.h : Declaration of the CUDPClient

#ifndef __UDPCLIENT_H_
#define __UDPCLIENT_H_

#include "resource.h"       // main symbols
#include "udp.h"

//
#define MAX_DWORDEXPANSION	32
#define MAX_IPEXPANSION		(26+60)
#define MAX_PORTEXPANSION	(5+16)
#define MAX_URLEXPANSION	(26+60+1+5)

//
struct ip4port {
	BYTE octet[4];
	WORD port;
};

/////////////////////////////////////////////////////////////////////////////
// CUDPClient
class ATL_NO_VTABLE CUDPClient :
public CComObjectRootEx<CComSingleThreadModel>,
public CComCoClass<CUDPClient, &CLSID_UDPClient>,
public IDispatchImpl<IUDPClient, &IID_IUDPClient, &LIBID_UDPCLIENTCOMLib>
{
public:
	CUDPClient();
	virtual ~CUDPClient();

	DECLARE_REGISTRY_RESOURCEID(IDR_UDPCLIENT)

	BEGIN_COM_MAP(CUDPClient)
	COM_INTERFACE_ENTRY(IUDPClient)
	COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()

// IUDPClient
public:
	STDMETHOD(get_thread)(long* pVal);
	STDMETHOD(get_version)(BSTR* pstr);
	STDMETHOD(get_copyright)(BSTR* pstr);
	STDMETHOD(get_description)(BSTR* pstr);
	STDMETHODIMP get_instance(long* pVal);
	STDMETHODIMP get_instances(long* pVal);

	STDMETHODIMP get_Log(BSTR* pstrText);
	STDMETHOD(ClearLog)();

	STDMETHOD(Open)(BSTR strip, BSTR strport, long* bconnected);
	STDMETHOD(Close)();
	STDMETHODIMP Send(BSTR strText, long* bytes);
	STDMETHOD(SendCSV)(BSTR strText, long* bytes);
	STDMETHODIMP Recv(BSTR* pstrText);
	STDMETHOD(RecvCSV)(BSTR* pstrText);

	STDMETHOD(put_timeout)(double seconds);
	STDMETHODIMP get_timeout(double* pseconds);

	STDMETHOD(get_sendlength)(long* pbytes);
	STDMETHOD(get_recvlength)(long* pbytes);
	STDMETHOD(get_buffersize)(long* pbytes);
	STDMETHOD(get_messagelength)(long* pbytes);
	STDMETHOD(get_bytesreceived)(long* pVal);
	STDMETHOD(get_bytessent)(long* pVal);

	STDMETHOD(get_localaddress)(BSTR* pstr);
	STDMETHOD(get_remoteaddress)(BSTR* pstr);
	STDMETHOD(get_udpsocket)(long* pVal);
	STDMETHOD(get_kbpssending)(double* pVal);
	STDMETHOD(get_kbpsreceiving)(double* pVal);

	STDMETHOD(get_senttimeout)(double* pVal);
	STDMETHOD(get_receivedtimeout)(double* pVal);

	STDMETHODIMP get_ping(long* pVal);

	STDMETHODIMP SendPacket(long*bytes);
	STDMETHODIMP RecvPacket(long*bytes);
	STDMETHODIMP packetclear();
	STDMETHODIMP get_packetlength(long* bytes);
	STDMETHODIMP addpacketnumber(BSTR strType, double val);
	STDMETHODIMP addpacketchar(BSTR str);
	STDMETHODIMP addpacketstring(BSTR str);
	STDMETHODIMP packetnumber(BSTR strType, double* val);
	STDMETHODIMP packetchar(BSTR* pstr);
	STDMETHODIMP packetstring(BSTR* pstr);
	STDMETHODIMP get_packetposition(long* bytes);
	STDMETHODIMP put_packetreposition(long bytes);

	STDMETHODIMP addpacketipport(BSTR strIP, int Port);
	STDMETHODIMP packetipport(BSTR* strIP, int* Port);

	STDMETHODIMP addpacketstringN(BSTR str);
	STDMETHODIMP packetstringN(long len, BSTR *pstr);
	STDMETHODIMP packetstringC(BSTR c, BSTR* pstr);

	STDMETHODIMP get_packetEOF(long* pbool);

	STDMETHODIMP get_is_connected(long* pstatus);

public:
	CLog log;

private:
	udp* w;

	char* m_packet;//[MAX_PACKET_SIZE];
	size_t m_packetlength;
	size_t m_packetposition;

	int m_instance;
	static int m_last_instance;
private:
	long size_t_to_long(size_t t);
	size_t long_to_size_t(long l);
};

#endif //__UDPCLIENT_H_
