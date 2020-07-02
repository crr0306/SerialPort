// SerialPort.cpp : Implementation of CSerialPortApp and DLL registration.

#include "stdafx.h"
#include "SerialPort.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CSerialPortApp theApp;

const GUID CDECL _tlid = { 0xF3B170FB, 0xCC6A, 0x4B16, { 0xA3, 0x37, 0x41, 0x47, 0xED, 0xBA, 0xA8, 0x90 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CSerialPortApp::InitInstance - DLL initialization

BOOL CSerialPortApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CSerialPortApp::ExitInstance - DLL termination

int CSerialPortApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
