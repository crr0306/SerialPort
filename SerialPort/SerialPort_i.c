

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_SerialPortLib,0xF3B170FB,0xCC6A,0x4B16,0xA3,0x37,0x41,0x47,0xED,0xBA,0xA8,0x90);


MIDL_DEFINE_GUID(IID, DIID__DSerialPort,0xED79AADD,0x0562,0x4661,0x96,0xD5,0xEF,0xA5,0xB1,0xB5,0xEC,0xDC);


MIDL_DEFINE_GUID(IID, DIID__DSerialPortEvents,0xE36A00B1,0x4DA4,0x4066,0x9F,0x2A,0x0A,0x43,0x9B,0x8A,0x8D,0x1A);


MIDL_DEFINE_GUID(CLSID, CLSID_SerialPort,0x7C1BC0B0,0x46CC,0x4A2F,0xB0,0xF0,0x37,0x94,0x8E,0x25,0xD5,0x57);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif


