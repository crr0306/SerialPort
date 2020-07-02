

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Jul 01 10:18:31 2020
 */
/* Compiler settings for SerialPort.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
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


#ifndef __SerialPortidl_h__
#define __SerialPortidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DSerialPort_FWD_DEFINED__
#define ___DSerialPort_FWD_DEFINED__
typedef interface _DSerialPort _DSerialPort;

#endif 	/* ___DSerialPort_FWD_DEFINED__ */


#ifndef ___DSerialPortEvents_FWD_DEFINED__
#define ___DSerialPortEvents_FWD_DEFINED__
typedef interface _DSerialPortEvents _DSerialPortEvents;

#endif 	/* ___DSerialPortEvents_FWD_DEFINED__ */


#ifndef __SerialPort_FWD_DEFINED__
#define __SerialPort_FWD_DEFINED__

#ifdef __cplusplus
typedef class SerialPort SerialPort;
#else
typedef struct SerialPort SerialPort;
#endif /* __cplusplus */

#endif 	/* __SerialPort_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_SerialPort_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_SerialPort_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_SerialPort_0000_0000_v0_0_s_ifspec;


#ifndef __SerialPortLib_LIBRARY_DEFINED__
#define __SerialPortLib_LIBRARY_DEFINED__

/* library SerialPortLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_SerialPortLib;

#ifndef ___DSerialPort_DISPINTERFACE_DEFINED__
#define ___DSerialPort_DISPINTERFACE_DEFINED__

/* dispinterface _DSerialPort */
/* [uuid] */ 


EXTERN_C const IID DIID__DSerialPort;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("ED79AADD-0562-4661-96D5-EFA5B1B5ECDC")
    _DSerialPort : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DSerialPortVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DSerialPort * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DSerialPort * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DSerialPort * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DSerialPort * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DSerialPort * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DSerialPort * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DSerialPort * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DSerialPortVtbl;

    interface _DSerialPort
    {
        CONST_VTBL struct _DSerialPortVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DSerialPort_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DSerialPort_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DSerialPort_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DSerialPort_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DSerialPort_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DSerialPort_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DSerialPort_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DSerialPort_DISPINTERFACE_DEFINED__ */


#ifndef ___DSerialPortEvents_DISPINTERFACE_DEFINED__
#define ___DSerialPortEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DSerialPortEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DSerialPortEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E36A00B1-4DA4-4066-9F2A-0A439B8A8D1A")
    _DSerialPortEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DSerialPortEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DSerialPortEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DSerialPortEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DSerialPortEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DSerialPortEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DSerialPortEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DSerialPortEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DSerialPortEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DSerialPortEventsVtbl;

    interface _DSerialPortEvents
    {
        CONST_VTBL struct _DSerialPortEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DSerialPortEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DSerialPortEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DSerialPortEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DSerialPortEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DSerialPortEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DSerialPortEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DSerialPortEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DSerialPortEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SerialPort;

#ifdef __cplusplus

class DECLSPEC_UUID("7C1BC0B0-46CC-4A2F-B0F0-37948E25D557")
SerialPort;
#endif
#endif /* __SerialPortLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


