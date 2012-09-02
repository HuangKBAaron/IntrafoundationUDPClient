

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Sep 01 18:38:42 2012
 */
/* Compiler settings for udpclientcom.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __udpclientcom_h__
#define __udpclientcom_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IUDPClient_FWD_DEFINED__
#define __IUDPClient_FWD_DEFINED__
typedef interface IUDPClient IUDPClient;
#endif 	/* __IUDPClient_FWD_DEFINED__ */


#ifndef __UDPClient_FWD_DEFINED__
#define __UDPClient_FWD_DEFINED__

#ifdef __cplusplus
typedef class UDPClient UDPClient;
#else
typedef struct UDPClient UDPClient;
#endif /* __cplusplus */

#endif 	/* __UDPClient_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IUDPClient_INTERFACE_DEFINED__
#define __IUDPClient_INTERFACE_DEFINED__

/* interface IUDPClient */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUDPClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F3244CB4-25BB-4909-B3FA-E547BFDF6779")
    IUDPClient : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_thread( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_version( 
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_copyright( 
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_description( 
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_instance( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_instances( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Log( 
            /* [retval][out] */ BSTR *pstrText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearLog( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR strip,
            /* [in] */ BSTR strport,
            /* [retval][out] */ long *bconnected) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Send( 
            /* [in] */ BSTR strText,
            /* [retval][out] */ long *bytes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Recv( 
            /* [retval][out] */ BSTR *pstrText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendCSV( 
            /* [in] */ BSTR strText,
            /* [retval][out] */ long *bytes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RecvCSV( 
            /* [retval][out] */ BSTR *pstrText) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_timeout( 
            /* [in] */ double seconds) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_timeout( 
            /* [retval][out] */ double *pseconds) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_sendlength( 
            /* [retval][out] */ long *pbytes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_recvlength( 
            /* [retval][out] */ long *pbytes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_buffersize( 
            /* [retval][out] */ long *pbytes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_messagelength( 
            /* [retval][out] */ long *pbytes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_bytessent( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_bytesreceived( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_localaddress( 
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_remoteaddress( 
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_udpsocket( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_kbpssending( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_kbpsreceiving( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_senttimeout( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_receivedtimeout( 
            /* [retval][out] */ double *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ping( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendPacket( 
            /* [retval][out] */ long *bytes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RecvPacket( 
            /* [retval][out] */ long *bytes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE packetclear( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_packetlength( 
            /* [retval][out] */ long *bytes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_packetposition( 
            /* [retval][out] */ long *bytes) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_packetreposition( 
            /* [in] */ long bytes) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE addpacketnumber( 
            /* [in] */ BSTR strType,
            /* [in] */ double val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE addpacketchar( 
            /* [in] */ BSTR str) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE addpacketstring( 
            /* [in] */ BSTR str) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE packetchar( 
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE packetstring( 
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE packetnumber( 
            /* [in] */ BSTR strType,
            /* [retval][out] */ double *val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE addpacketipport( 
            /* [in] */ BSTR strIP,
            /* [in] */ int Port) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE packetipport( 
            /* [out] */ BSTR *strIP,
            /* [out] */ int *Port) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE addpacketstringN( 
            /* [in] */ BSTR str) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE packetstringN( 
            /* [in] */ long len,
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE packetstringC( 
            /* [in] */ BSTR c,
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_packetEOF( 
            /* [retval][out] */ long *pbool) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_is_connected( 
            /* [retval][out] */ long *status) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUDPClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUDPClient * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUDPClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUDPClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUDPClient * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUDPClient * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUDPClient * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUDPClient * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_thread )( 
            IUDPClient * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_version )( 
            IUDPClient * This,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_copyright )( 
            IUDPClient * This,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_description )( 
            IUDPClient * This,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_instance )( 
            IUDPClient * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_instances )( 
            IUDPClient * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Log )( 
            IUDPClient * This,
            /* [retval][out] */ BSTR *pstrText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearLog )( 
            IUDPClient * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IUDPClient * This,
            /* [in] */ BSTR strip,
            /* [in] */ BSTR strport,
            /* [retval][out] */ long *bconnected);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IUDPClient * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Send )( 
            IUDPClient * This,
            /* [in] */ BSTR strText,
            /* [retval][out] */ long *bytes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Recv )( 
            IUDPClient * This,
            /* [retval][out] */ BSTR *pstrText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendCSV )( 
            IUDPClient * This,
            /* [in] */ BSTR strText,
            /* [retval][out] */ long *bytes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RecvCSV )( 
            IUDPClient * This,
            /* [retval][out] */ BSTR *pstrText);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_timeout )( 
            IUDPClient * This,
            /* [in] */ double seconds);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_timeout )( 
            IUDPClient * This,
            /* [retval][out] */ double *pseconds);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_sendlength )( 
            IUDPClient * This,
            /* [retval][out] */ long *pbytes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_recvlength )( 
            IUDPClient * This,
            /* [retval][out] */ long *pbytes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_buffersize )( 
            IUDPClient * This,
            /* [retval][out] */ long *pbytes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_messagelength )( 
            IUDPClient * This,
            /* [retval][out] */ long *pbytes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_bytessent )( 
            IUDPClient * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_bytesreceived )( 
            IUDPClient * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_localaddress )( 
            IUDPClient * This,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_remoteaddress )( 
            IUDPClient * This,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_udpsocket )( 
            IUDPClient * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_kbpssending )( 
            IUDPClient * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_kbpsreceiving )( 
            IUDPClient * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_senttimeout )( 
            IUDPClient * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_receivedtimeout )( 
            IUDPClient * This,
            /* [retval][out] */ double *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ping )( 
            IUDPClient * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendPacket )( 
            IUDPClient * This,
            /* [retval][out] */ long *bytes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RecvPacket )( 
            IUDPClient * This,
            /* [retval][out] */ long *bytes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *packetclear )( 
            IUDPClient * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_packetlength )( 
            IUDPClient * This,
            /* [retval][out] */ long *bytes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_packetposition )( 
            IUDPClient * This,
            /* [retval][out] */ long *bytes);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_packetreposition )( 
            IUDPClient * This,
            /* [in] */ long bytes);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *addpacketnumber )( 
            IUDPClient * This,
            /* [in] */ BSTR strType,
            /* [in] */ double val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *addpacketchar )( 
            IUDPClient * This,
            /* [in] */ BSTR str);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *addpacketstring )( 
            IUDPClient * This,
            /* [in] */ BSTR str);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *packetchar )( 
            IUDPClient * This,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *packetstring )( 
            IUDPClient * This,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *packetnumber )( 
            IUDPClient * This,
            /* [in] */ BSTR strType,
            /* [retval][out] */ double *val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *addpacketipport )( 
            IUDPClient * This,
            /* [in] */ BSTR strIP,
            /* [in] */ int Port);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *packetipport )( 
            IUDPClient * This,
            /* [out] */ BSTR *strIP,
            /* [out] */ int *Port);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *addpacketstringN )( 
            IUDPClient * This,
            /* [in] */ BSTR str);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *packetstringN )( 
            IUDPClient * This,
            /* [in] */ long len,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *packetstringC )( 
            IUDPClient * This,
            /* [in] */ BSTR c,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_packetEOF )( 
            IUDPClient * This,
            /* [retval][out] */ long *pbool);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_is_connected )( 
            IUDPClient * This,
            /* [retval][out] */ long *status);
        
        END_INTERFACE
    } IUDPClientVtbl;

    interface IUDPClient
    {
        CONST_VTBL struct IUDPClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUDPClient_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUDPClient_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUDPClient_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUDPClient_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IUDPClient_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IUDPClient_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IUDPClient_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IUDPClient_get_thread(This,pVal)	\
    ( (This)->lpVtbl -> get_thread(This,pVal) ) 

#define IUDPClient_get_version(This,pstr)	\
    ( (This)->lpVtbl -> get_version(This,pstr) ) 

#define IUDPClient_get_copyright(This,pstr)	\
    ( (This)->lpVtbl -> get_copyright(This,pstr) ) 

#define IUDPClient_get_description(This,pstr)	\
    ( (This)->lpVtbl -> get_description(This,pstr) ) 

#define IUDPClient_get_instance(This,pVal)	\
    ( (This)->lpVtbl -> get_instance(This,pVal) ) 

#define IUDPClient_get_instances(This,pVal)	\
    ( (This)->lpVtbl -> get_instances(This,pVal) ) 

#define IUDPClient_get_Log(This,pstrText)	\
    ( (This)->lpVtbl -> get_Log(This,pstrText) ) 

#define IUDPClient_ClearLog(This)	\
    ( (This)->lpVtbl -> ClearLog(This) ) 

#define IUDPClient_Open(This,strip,strport,bconnected)	\
    ( (This)->lpVtbl -> Open(This,strip,strport,bconnected) ) 

#define IUDPClient_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IUDPClient_Send(This,strText,bytes)	\
    ( (This)->lpVtbl -> Send(This,strText,bytes) ) 

#define IUDPClient_Recv(This,pstrText)	\
    ( (This)->lpVtbl -> Recv(This,pstrText) ) 

#define IUDPClient_SendCSV(This,strText,bytes)	\
    ( (This)->lpVtbl -> SendCSV(This,strText,bytes) ) 

#define IUDPClient_RecvCSV(This,pstrText)	\
    ( (This)->lpVtbl -> RecvCSV(This,pstrText) ) 

#define IUDPClient_put_timeout(This,seconds)	\
    ( (This)->lpVtbl -> put_timeout(This,seconds) ) 

#define IUDPClient_get_timeout(This,pseconds)	\
    ( (This)->lpVtbl -> get_timeout(This,pseconds) ) 

#define IUDPClient_get_sendlength(This,pbytes)	\
    ( (This)->lpVtbl -> get_sendlength(This,pbytes) ) 

#define IUDPClient_get_recvlength(This,pbytes)	\
    ( (This)->lpVtbl -> get_recvlength(This,pbytes) ) 

#define IUDPClient_get_buffersize(This,pbytes)	\
    ( (This)->lpVtbl -> get_buffersize(This,pbytes) ) 

#define IUDPClient_get_messagelength(This,pbytes)	\
    ( (This)->lpVtbl -> get_messagelength(This,pbytes) ) 

#define IUDPClient_get_bytessent(This,pVal)	\
    ( (This)->lpVtbl -> get_bytessent(This,pVal) ) 

#define IUDPClient_get_bytesreceived(This,pVal)	\
    ( (This)->lpVtbl -> get_bytesreceived(This,pVal) ) 

#define IUDPClient_get_localaddress(This,pstr)	\
    ( (This)->lpVtbl -> get_localaddress(This,pstr) ) 

#define IUDPClient_get_remoteaddress(This,pstr)	\
    ( (This)->lpVtbl -> get_remoteaddress(This,pstr) ) 

#define IUDPClient_get_udpsocket(This,pVal)	\
    ( (This)->lpVtbl -> get_udpsocket(This,pVal) ) 

#define IUDPClient_get_kbpssending(This,pVal)	\
    ( (This)->lpVtbl -> get_kbpssending(This,pVal) ) 

#define IUDPClient_get_kbpsreceiving(This,pVal)	\
    ( (This)->lpVtbl -> get_kbpsreceiving(This,pVal) ) 

#define IUDPClient_get_senttimeout(This,pVal)	\
    ( (This)->lpVtbl -> get_senttimeout(This,pVal) ) 

#define IUDPClient_get_receivedtimeout(This,pVal)	\
    ( (This)->lpVtbl -> get_receivedtimeout(This,pVal) ) 

#define IUDPClient_get_ping(This,pVal)	\
    ( (This)->lpVtbl -> get_ping(This,pVal) ) 

#define IUDPClient_SendPacket(This,bytes)	\
    ( (This)->lpVtbl -> SendPacket(This,bytes) ) 

#define IUDPClient_RecvPacket(This,bytes)	\
    ( (This)->lpVtbl -> RecvPacket(This,bytes) ) 

#define IUDPClient_packetclear(This)	\
    ( (This)->lpVtbl -> packetclear(This) ) 

#define IUDPClient_get_packetlength(This,bytes)	\
    ( (This)->lpVtbl -> get_packetlength(This,bytes) ) 

#define IUDPClient_get_packetposition(This,bytes)	\
    ( (This)->lpVtbl -> get_packetposition(This,bytes) ) 

#define IUDPClient_put_packetreposition(This,bytes)	\
    ( (This)->lpVtbl -> put_packetreposition(This,bytes) ) 

#define IUDPClient_addpacketnumber(This,strType,val)	\
    ( (This)->lpVtbl -> addpacketnumber(This,strType,val) ) 

#define IUDPClient_addpacketchar(This,str)	\
    ( (This)->lpVtbl -> addpacketchar(This,str) ) 

#define IUDPClient_addpacketstring(This,str)	\
    ( (This)->lpVtbl -> addpacketstring(This,str) ) 

#define IUDPClient_packetchar(This,pstr)	\
    ( (This)->lpVtbl -> packetchar(This,pstr) ) 

#define IUDPClient_packetstring(This,pstr)	\
    ( (This)->lpVtbl -> packetstring(This,pstr) ) 

#define IUDPClient_packetnumber(This,strType,val)	\
    ( (This)->lpVtbl -> packetnumber(This,strType,val) ) 

#define IUDPClient_addpacketipport(This,strIP,Port)	\
    ( (This)->lpVtbl -> addpacketipport(This,strIP,Port) ) 

#define IUDPClient_packetipport(This,strIP,Port)	\
    ( (This)->lpVtbl -> packetipport(This,strIP,Port) ) 

#define IUDPClient_addpacketstringN(This,str)	\
    ( (This)->lpVtbl -> addpacketstringN(This,str) ) 

#define IUDPClient_packetstringN(This,len,pstr)	\
    ( (This)->lpVtbl -> packetstringN(This,len,pstr) ) 

#define IUDPClient_packetstringC(This,c,pstr)	\
    ( (This)->lpVtbl -> packetstringC(This,c,pstr) ) 

#define IUDPClient_get_packetEOF(This,pbool)	\
    ( (This)->lpVtbl -> get_packetEOF(This,pbool) ) 

#define IUDPClient_get_is_connected(This,status)	\
    ( (This)->lpVtbl -> get_is_connected(This,status) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUDPClient_INTERFACE_DEFINED__ */



#ifndef __UDPCLIENTCOMLib_LIBRARY_DEFINED__
#define __UDPCLIENTCOMLib_LIBRARY_DEFINED__

/* library UDPCLIENTCOMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_UDPCLIENTCOMLib;

EXTERN_C const CLSID CLSID_UDPClient;

#ifdef __cplusplus

class DECLSPEC_UUID("D1FB6AA6-D120-4425-BFC6-EE79361355A7")
UDPClient;
#endif
#endif /* __UDPCLIENTCOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


