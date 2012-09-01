// test_harness.cpp : Defines the entry point for the console application.
//
/*
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
#include "Log.h"*/

#include "stdafx.h"

//#include "windows.h"
//#include "stdio.h"

// _open file handling
#include "io.h"
#include <fcntl.h>

//#include <comdef.h> //BSTR
#include "sys\stat.h" // _stat

//
#include "string.h"
#include <time.h>
#include <conio.h>

//
//#include "..\..\udpclientcom\udp.h"

#include "Log.h"
//#include "ErrorStringWSA.h"
#include "udp.h"

int _tmain(int argc, _TCHAR* argv[])
{
	printf("This is a udp class debugging test harness.\n");

	string strError;
	strError="";


	///////////////////////////////////////////////////////////////////////////
	printf("-------------------------------------------\n");
	{
		udp *w=new udp();
		printf("\n\n ** sock - > %d\n",w->udpsocket());

		//
		int lp;
		int rp;
		char *lip=NULL;
		char *rip=NULL;
		w->endpoints(lip,lp,rip,rp);
		printf("[local -> %s:%d]\n",lip,lp);
		printf("[remote -> %s:%d]\n",rip,rp);

		char *buf=new char[MAX_ADDRESS+2];
		//memset(buf,0,MAX_ADDRESS);
		_snprintf(buf,MAX_ADDRESS,"local -> %s:%d",lip,lp);
		size_t buflength=strlen(buf);
		printf(" buf - > %s\n",buf);
		delete [] buf;
	}




	///////////////////////////////////////////////////////////////////////////
	printf("-------------------------------------------\n");

	printf("Looking for Half-Life server on UDP port 27910...\n\n");

	// 128.121.95.31:27016

	//	w=new udp("212.137.72.133","27963",strError);
	//27910
	// 212.48.128.177
	// 128.197.213.103
	// 206.170.15.58
	// 207.206.185.7
	//129.105.37.241
	{
		//		 128.121.95.31:27016
		udp *w;
		w=new udp("gaming.twcny.rr.com","27015");
		if(w)
		{
			printf("udp opened.\n");

			//
			w->timeout(4,0);
			printf("setting timeout 4.000.\n");
			printf("err:%s\n",strError.c_str());
			strError="";
			printf("\n\n");
			printf("**********\n");

			//
			int slength=0;
			int rlength=0;
			char *r=NULL;

			//
			printf("\n");
			//char *s1="\0xff\0xff\0xff\0xffstatus\n";
			//char *s1="\0xff\0xff\0xff\0xffstatus\n";
			char *s1="ÿÿÿÿplayers\n";
			size_t sendlen=strlen(s1);
			slength=w->Send(s1,sendlen);
			printf("sendlen=%d.\n",sendlen);
			printf("slength=%d.\n",slength);
			printf("s1=%s.\n",s1);
			printf("err:%s\n",strError.c_str());
			printf("**********\n");

			//
			printf("\n");
			rlength=w->Recv(r);
			printf("rlength=%d.\n",rlength);
			printf("err:%s\n",strError.c_str());
			if(r)
				printf("recv:%s\n",r);


			//
			size_t sendlength;
			size_t recvlength;
			size_t buffersize;
			size_t messagelength;
			w->bufferlengths(sendlength,recvlength,buffersize,messagelength);
			printf(
				"sendlength=%u recvlength=%u buffersize=%u messagelength=%u\n",
				sendlength,recvlength,buffersize,messagelength
				);


			//
			size_t this_bytes_sent;
			size_t this_bytes_received;
			w->bytestransferred(this_bytes_sent, this_bytes_received);
			printf(
				"bytes_sent=%d bytes_received=%d \n",
				this_bytes_sent, this_bytes_received
				);

			//
			/*double this_sent_timeout;
			double this_received_timeout;
			w->timeouts(this_sent_timeout, this_received_timeout);
			printf(
				"sent_timeout=%f received_timeout=%f\n",
				this_sent_timeout, this_received_timeout
				);*/

			printf(" sock - > %d\n",w->udpsocket());

			//
			int lp;
			int rp;
			char *lip=NULL;
			char *rip=NULL;
			w->endpoints(lip,lp,rip,rp);
			printf("[local -> %s:%d]\n",lip,lp);
			printf("[remote -> %s:%d]\n",rip,rp);

			char *buf=new char[MAX_ADDRESS];
			memset(buf,0,MAX_ADDRESS);
			sprintf(buf,"local -> %s:%d",lip,lp);
			size_t buflength=strlen(buf);
			printf(" buf - > %s\n",buf);
			delete [] buf;

			//
			printf("closing udp.\n");
			//		w->close();
		}
		else
		{
			printf("!w\n");
		}
	}





	///////////////////////////////////////////////////////////////////////////
	printf("-------------------------------------------\n");

	//	printf("Looking for Quake II server on UDP port 27910...\n\n");
	printf("Looking for Quake II server on UDP port 27910...\n\n");


	// 128.121.95.31:27016


	//	w=new udp("212.137.72.133","27963",strError);
	//27910
	// 212.48.128.177
	// 128.197.213.103
	// 206.170.15.58
	// 207.206.185.7
	//129.105.37.241
	{
		//		 128.121.95.31:27016
		udp *w;
		w=new udp("127.0.0.1","27910");
		if(w)
		{
			printf("udp opened.\n");

			//
			w->timeout(2,0);
			printf("setting timeout 4.000.\n");
			printf("err:%s\n",strError.c_str());
			strError="";
			printf("\n\n");
			printf("**********\n");

			//
			int slength=0;
			int rlength=0;
			char *r=NULL;

			//
			printf("\n");
			//char *s1="\0xff\0xff\0xff\0xffstatus\n";
			//char *s1="\0xff\0xff\0xff\0xffstatus\n";
			char *s1="ÿÿÿÿstatus\n";
			size_t sendlen=strlen(s1);
			//		sendlength=w->SendTo(s1,sendlen,"212.48.128.177","27910",strError);
			slength=w->Send(s1,sendlen);
			printf("sendlen=%d.\n",sendlen);
			printf("slength=%d.\n",slength);
			printf("s1=%s.\n",s1);
			printf("err:%s\n",strError.c_str());
			printf("**********\n");

			//
			printf("\n");
			//		recvlength=w->RecvFrom(&r,"212.48.128.177","27910",strError);
			rlength=w->Recv(r);
			printf("rlength=%d.\n",rlength);
			printf("err:%s\n",strError.c_str());
			if(r)
				printf("recv:%s\n",r);


			//
			size_t sendlength;
			size_t recvlength;
			size_t buffersize;
			size_t messagelength;
			w->bufferlengths(sendlength,recvlength,buffersize,messagelength);
			printf(
				"sendlength=%d recvlength=%d buffersize=%d messagelength=%d\n",
				sendlength,recvlength,buffersize,messagelength
				);


			//
			size_t this_bytes_sent;
			size_t this_bytes_received;
			w->bytestransferred(this_bytes_sent, this_bytes_received);
			printf(
				"bytes_sent=%d bytes_received=%d \n",
				this_bytes_sent, this_bytes_received
				);

			//
/*			double this_sent_timeout;
			double this_received_timeout;
			w->timeouts(this_sent_timeout, this_received_timeout);
			printf(
				"sent_timeout=%f received_timeout=%f\n",
				this_sent_timeout, this_received_timeout
				);
				*/
			printf(" sock - > %d\n",w->udpsocket());

			//
			int lp;
			int rp;
			char *lip=NULL;
			char *rip=NULL;
			w->endpoints(lip,lp,rip,rp);
			printf("[local -> %s:%d]\n",lip,lp);
			printf("[remote -> %s:%d]\n",rip,rp);

			char *buf=new char[MAX_ADDRESS];
			memset(buf,0,MAX_ADDRESS);
			sprintf(buf,"local -> %s:%d",lip,lp);
			size_t buflength=strlen(buf);
			printf(" buf - > %s\n",buf);
			delete [] buf;

			//
			printf("closing udp.\n");
			//		w->close();
		}
		else
		{
			printf("!w\n");
		}
	}











	//////////////////////////////////////////////////////////////

	printf("-------------------------------------------\n");
	{
		udp *w=new udp();
		printf("\n\n ** sock - > %d\n",w->udpsocket());

		//
		int lp;
		int rp;
		char *lip=NULL;
		char *rip=NULL;
		w->endpoints(lip,lp,rip,rp);
		printf("[local -> %s:%d]\n",lip,lp);
		printf("[remote -> %s:%d]\n",rip,rp);

		char *buf=new char[MAX_ADDRESS];
		memset(buf,0,MAX_ADDRESS);
		sprintf(buf,"local -> %s:%d",lip,lp);
		size_t buflength=strlen(buf);
		printf(" buf - > %s\n",buf);
		delete [] buf;
	}


	/*{
	udp *w;
	w=NULL;

	printf("\n\n ** sock - > %d\n",w->udpsocket());

	//
	int lp;
	int rp;
	char *lip=NULL;
	char *rip=NULL;
	w->endpoints(&lip,lp,&rip,rp);
	printf("[local -> %s:%d]\n",lip,lp);
	printf("[remote -> %s:%d]\n",rip,rp);

	char *buf=new char[MAX_ADDRESS];
	memset(buf,0,MAX_ADDRESS);
	sprintf(buf,"local -> %s:%d",lip,lp);
	int buflength=strlen(buf);
	printf(" buf - > %s\n",buf);
	delete [] buf;
	}
	*/

	printf("PRESS"); _getch();
	return 0;
}

