#pragma once

// SerialPortCtrl.h : Declaration of the CSerialPortCtrl ActiveX Control class.


// CSerialPortCtrl : See SerialPortCtrl.cpp for implementation.

class CSerialPortCtrl : public COleControl
{
	DECLARE_DYNCREATE(CSerialPortCtrl)

// Constructor
public:
	CSerialPortCtrl();

// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// Implementation
protected:
	~CSerialPortCtrl();

	DECLARE_OLECREATE_EX(CSerialPortCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CSerialPortCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CSerialPortCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CSerialPortCtrl)		// Type name and misc status

// Message maps
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	DECLARE_EVENT_MAP()
public:
	//DWORD WINAPI Fun(LPVOID lpParamter);
	void CloseComm1();//启动时先关闭，保证可以连续使用
	void CloseComm();
	char* ReceiveChar2();
	char ReceiveChar();
	void  WriteChar(BYTE buffer[6]);
	void Fun();
// Dispatch and event IDs
public:
	enum {
		dispidOpenPort = 5L,
		dispidMainThread = 3L,
		eventidReadKh = 1L,
		dispidClosePort = 4L,
	
	};
	
protected:
	
	void ClosePort();

	void ReadKh(LPCTSTR kh)
	{
		FireEvent(eventidReadKh, EVENT_PARAM(VTS_BSTR), kh);
	}
	void MainThread(LPCTSTR portname);
	LONG OpenPort(LPCTSTR portname);

	

};

