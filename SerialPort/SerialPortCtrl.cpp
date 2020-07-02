// SerialPortCtrl.cpp : Implementation of the CSerialPortCtrl ActiveX Control class.

#include "stdafx.h"
#include "SerialPort.h"
#include "SerialPortCtrl.h"
#include "SerialPortPropPage.h"
#include "afxdialogex.h"
#include "afxtempl.h"
HANDLE hComm;
OVERLAPPED m_ov;//重叠方式
COMSTAT comstat;
COMSTAT comstat2;
DWORD m_dwCommEvents;
DWORD dwBytesRead2 = 1024;//长度数

//线程
#include <iostream>
#include <windows.h>
#include<string.h>
using namespace std;
HANDLE hMutex;
CString kh = NULL;//卡号
//CString kh = NULL;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CSerialPortCtrl, COleControl)

// Message map

BEGIN_MESSAGE_MAP(CSerialPortCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// Dispatch map

BEGIN_DISPATCH_MAP(CSerialPortCtrl, COleControl)
	DISP_FUNCTION_ID(CSerialPortCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)


	DISP_FUNCTION_ID(CSerialPortCtrl, "ClosePort", dispidClosePort, ClosePort, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CSerialPortCtrl, "MainThread", dispidMainThread, MainThread, VT_EMPTY, VTS_BSTR)
	DISP_FUNCTION_ID(CSerialPortCtrl, "OpenPort", dispidOpenPort, OpenPort, VT_I4, VTS_BSTR)
END_DISPATCH_MAP()

// Event map

BEGIN_EVENT_MAP(CSerialPortCtrl, COleControl)
	EVENT_CUSTOM_ID("ReadKh", eventidReadKh, ReadKh, VTS_BSTR)
END_EVENT_MAP()

// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CSerialPortCtrl, 1)
	PROPPAGEID(CSerialPortPropPage::guid)
END_PROPPAGEIDS(CSerialPortCtrl)

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CSerialPortCtrl, "SERIALPORT.SerialPortCtrl.1",
	0x7c1bc0b0, 0x46cc, 0x4a2f, 0xb0, 0xf0, 0x37, 0x94, 0x8e, 0x25, 0xd5, 0x57)

	// Type library ID and version

	IMPLEMENT_OLETYPELIB(CSerialPortCtrl, _tlid, _wVerMajor, _wVerMinor)

	// Interface IDs

	const IID IID_DSerialPort = { 0xED79AADD, 0x562, 0x4661, { 0x96, 0xD5, 0xEF, 0xA5, 0xB1, 0xB5, 0xEC, 0xDC } };
const IID IID_DSerialPortEvents = { 0xE36A00B1, 0x4DA4, 0x4066, { 0x9F, 0x2A, 0xA, 0x43, 0x9B, 0x8A, 0x8D, 0x1A } };

// Control type information

static const DWORD _dwSerialPortOleMisc =
OLEMISC_ACTIVATEWHENVISIBLE |
OLEMISC_SETCLIENTSITEFIRST |
OLEMISC_INSIDEOUT |
OLEMISC_CANTLINKINSIDE |
OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CSerialPortCtrl, IDS_SERIALPORT, _dwSerialPortOleMisc)

// CSerialPortCtrl::CSerialPortCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CSerialPortCtrl

BOOL CSerialPortCtrl::CSerialPortCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
		AfxGetInstanceHandle(),
		m_clsid,
		m_lpszProgID,
		IDS_SERIALPORT,
		IDB_SERIALPORT,
		afxRegApartmentThreading,
		_dwSerialPortOleMisc,
		_tlid,
		_wVerMajor,
		_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CSerialPortCtrl::CSerialPortCtrl - Constructor

CSerialPortCtrl::CSerialPortCtrl()
{
	InitializeIIDs(&IID_DSerialPort, &IID_DSerialPortEvents);
	// TODO: Initialize your control's instance data here.
}

// CSerialPortCtrl::~CSerialPortCtrl - Destructor

CSerialPortCtrl::~CSerialPortCtrl()
{
	// TODO: Cleanup your control's instance data here.
}

// CSerialPortCtrl::OnDraw - Drawing function

void CSerialPortCtrl::OnDraw(
	CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CSerialPortCtrl::DoPropExchange - Persistence support

void CSerialPortCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}


// CSerialPortCtrl::OnResetState - Reset control to default state

void CSerialPortCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


// CSerialPortCtrl::AboutBox - Display an "About" box to the user

void CSerialPortCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_SERIALPORT);
	dlgAbout.DoModal();
}


// CSerialPortCtrl message handlers
//打开或者创建串口
LONG CSerialPortCtrl::OpenPort(LPCTSTR portname)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your dispatch handler code here

	hComm = CreateFile((LPTSTR)portname, //串口号
		GENERIC_READ | GENERIC_WRITE, //允许读写
		0, //通讯设备必须以独占方式打开
		0, //无安全属性
		OPEN_EXISTING, //通讯设备已存在
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, //重叠
		0); //通讯设备不能用模板打开
	if (hComm == (HANDLE)-1)
	{
		CloseHandle(hComm);
		hComm = NULL;
		return 0;
	}
	SetupComm(hComm, 10024, 1024); //输入缓冲区和输出缓冲区的大小都是100  
	COMMTIMEOUTS TimeOuts;
	//设定读超时  
	TimeOuts.ReadIntervalTimeout = MAXDWORD;
	TimeOuts.ReadTotalTimeoutMultiplier = 0;
	TimeOuts.ReadTotalTimeoutConstant = 0;
	//在读一次输入缓冲区的内容后读操作就立即返回，  
	//而不管是否读入了要求的字符。  
	//设定写超时  
	TimeOuts.WriteTotalTimeoutMultiplier = 100;
	TimeOuts.WriteTotalTimeoutConstant = 500;
	SetCommTimeouts(hComm, &TimeOuts); //设置超时  

	DCB dcb;
	GetCommState(hComm, &dcb);
	dcb.BaudRate = 9600; //波特率为9600  
	dcb.ByteSize = 8; //每个字节有8位  
	dcb.Parity = NOPARITY; //无奇偶校验位  
	dcb.StopBits = 1; //两个停止位  
	SetCommState(hComm, &dcb);
	PurgeComm(hComm, PURGE_TXCLEAR | PURGE_RXCLEAR);
	return 1;
}



void  CSerialPortCtrl::WriteChar(BYTE buffer[6])
{
	DWORD  dwBytesWritten = 6;//长度
	BOOL bWriteStat;//判断是否写好数据
	bWriteStat = WriteFile(hComm, buffer, dwBytesWritten, &dwBytesWritten, &m_ov);

	if (!bWriteStat){
		if (GetLastError() == ERROR_IO_PENDING)
		{
			/* 使用WaitForSingleObject函数等待，直到读操作完成或延时已达到2秒钟,当串口读操作进行完毕后，m_osRead的hEvent事件会变为有信号  
			参数1为句柄，
			参数2为时间间隔，当它为INFINITE时，对象被触发信号后，函数才会返回*/
			WaitForSingleObject(m_ov.hEvent, INFINITE);
			Sleep(200);
		}
	}
	//return dwBytesWritten;
}



//从串口读取数据，返回一个字符
char CSerialPortCtrl::ReceiveChar()
{
	/*
	-hFile：串口句柄
	-lpBuffer：存储被读出数据的首地址--数组名
	-nNumberOfBytesToRead：准备读出的字节个数
	-NumberOfBytesRead：实际读出的字节个数--地址
	-lpOverlapped：异步I/O结构
	*/

	char lpInBuffer[6];//存储
	DWORD dwBytesRead = 6;//长度数
	BOOL bReadStatus;//读之后结果
	DWORD dwErrorFlags;
	/*此函数清除硬件的通讯错误以及获取通讯设备的当前状态*/
	ClearCommError(hComm, &dwErrorFlags, &comstat);
	//cbInQue成员变量，该成员变量的值代表输入缓冲区的字节数，即接收到的数据数量 
	dwBytesRead = min(dwBytesRead, (DWORD)comstat.cbInQue);
	if (!comstat.cbInQue)
	{
		return 0;
	}

	
	bReadStatus = ReadFile(hComm, lpInBuffer, dwBytesRead, &dwBytesRead, &m_ov);
	//如果 ReadFile 函数返回的是FALSE

	if (!bReadStatus)
	{
		if (GetLastError() == ERROR_IO_PENDING)
		{
			/* GetOverlappedResult：是否等待重叠完成 当
			函数的最后一个参数设为 TRUE, 则函数会一直等待,直到读操作完成或由于错误而返回.*/
			GetOverlappedResult(hComm, &m_ov, &dwBytesRead, TRUE);
			//PurgeComm(hComm, PURGE_TXABORT |PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
			return lpInBuffer[0];
		}
		return lpInBuffer[0];
	}
	return lpInBuffer[0];
}

//从串口中读取，返回一个数组
char*   CSerialPortCtrl::ReceiveChar2()
{ 
	char* str=new char[100]; //存储
	BOOL bReadStatus;//是否读取成功
	DWORD dwErrorFlags;
	/*此函数清除硬件的通讯错误以及获取通讯设备的当前状态comstat*/
	ClearCommError(hComm, &dwErrorFlags, &comstat2);
	//cbInQue成员变量，该成员变量的值代表输入缓冲区的字节数，即接收到的数据数量 
	dwBytesRead2 = max(dwBytesRead2, (DWORD)comstat2.cbInQue);
	bReadStatus = ReadFile(hComm, str, dwBytesRead2, &dwBytesRead2, &m_ov);
	int length1 = strlen(str);
	if (!bReadStatus)
	{
		if (GetLastError() == ERROR_IO_PENDING)
		{		
			GetOverlappedResult(hComm, &m_ov, &dwBytesRead2, TRUE);			
			return str;
		}		
		return str;
	}	
	return str;
}


//关闭按钮功能

void CSerialPortCtrl::ClosePort()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your dispatch handler code here
	//禁止串行端口所有事件
	SetCommMask(hComm, 0);
	//清除数据终端就绪信号
	EscapeCommFunction(hComm, CLRDTR);
	//丢弃通信资源的输出或输入缓冲区字符并终止在通信资源上挂起的读、写操操作
	PurgeComm(hComm, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
	CloseHandle(hComm);
	hComm = NULL;
	MessageBox(_T("串口关闭"));
}

void CSerialPortCtrl::CloseComm1(){
	//禁止串行端口所有事件
	SetCommMask(hComm, 0);
	//清除数据终端就绪信号
	EscapeCommFunction(hComm, CLRDTR);
	//丢弃通信资源的输出或输入缓冲区字符并终止在通信资源上挂起的读、写操操作
	PurgeComm(hComm, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
	CloseHandle(hComm);
	hComm = NULL;

}
void CSerialPortCtrl::CloseComm(){
	//禁止串行端口所有事件
	SetCommMask(hComm, 0);
	//清除数据终端就绪信号
	EscapeCommFunction(hComm, CLRDTR);
	//丢弃通信资源的输出或输入缓冲区字符并终止在通信资源上挂起的读、写操操作
	PurgeComm(hComm, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
	CloseHandle(hComm);
	hComm = NULL;
	AfxMessageBox(_T("请重新点击刷卡按钮"));

}
void CSerialPortCtrl::Fun()
{
	// PurgeComm(hComm, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
	//防止前面几次没有读取到，那么需要循环多读取几次。
	//不用考虑用户多次刷一张卡，而多次得到这张卡号。
	char *str;//读取串口中的数据，返回一个数组
	//kh = _T("");
	int count = 0;
	str = ReceiveChar2();
	while ((++count)<400)
	{
		//Sleep(5000);
		kh = _T("");
		str = ReceiveChar2();
		CString cs1[1024] = { 0 };//临时数据，存储字符数组
		//只取16进制的后两位
		for (int i = 0; i < comstat2.cbInQue; i++)
		{
			cs1[i].Format(_T("%02x"), str[i] & 0xFF);
			kh = kh + cs1[i];
		}
		//将字符剔除，只输出
		for (int i = 0; i < 6; i++)
		{
			kh.Remove('a' + i);
		}
		//kh不为空,则退出
		if (kh != _T(""))
		{
		    AfxMessageBox(kh);
		    ReadKh(kh);
			//PurgeComm(hComm, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
			break;	
		}
		//AfxMessageBox(kh);
	}
		//清空输出和输入缓冲区
	
}

DWORD WINAPI  TmpCallInstance(LPVOID lpParamter){
	CSerialPortCtrl *t = (CSerialPortCtrl*)lpParamter;
	t->Fun();
	return 1;
}

void CSerialPortCtrl::MainThread(LPCTSTR portname)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your dispatch handler code here
	/*(1)打开串口
	（2）复位：0x1A,	0x0D,0x00,	0x00,0x1B,	0x42
	（3）串口全部启动数据： 1A 06 66 01 1B A2*/
	CloseComm1();
	BYTE buffer1[6];//复位
	buffer1[0] = 0x1A;
	buffer1[1] = 0x0D;
	buffer1[2] = 0x00;
	buffer1[3] = 0x00;
	buffer1[4] = 0x1B;
	buffer1[5] = 0x42;

	BYTE buffer2[6];//串口全部启动数据
	buffer2[0] = 0x1A;
	buffer2[1] = 0x06;
	buffer2[2] = 0x66;
	buffer2[3] = 0x01;
	buffer2[4] = 0x1B;
	buffer2[5] = 0xA2;
	BYTE s=NULL;
	
	PurgeComm(hComm, PURGE_TXCLEAR | PURGE_RXCLEAR);
	if (OpenPort(portname) == 1)
	{
		//MessageBox(_T("串口打开成功,且稍等刷卡"));	
		//Sleep(2000);
		WriteChar(buffer1);
		WriteChar(buffer2);
		s = ReceiveChar(); 
		if (s== (0xAA))
		{
			MessageBox(_T("串口启动数据写入成功，且请刷卡"));
			Sleep(1000);
			HANDLE hThread = CreateThread(NULL, 0, &TmpCallInstance, this, 0, 0);
			CloseHandle(hThread);
			//PurgeComm(hComm, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
			//MessageBox(kh);
			//return;
			
		}
		else
		{
			//PurgeComm(hComm, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
			MessageBox(_T("串口启动数据写入失败"));
			CloseComm();
			
		}
	}
	else
	{
		//PurgeComm(hComm, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
		MessageBox(_T("串口打开成失败"));
		CloseComm();
		
	}
	
}


