// SerialPortPropPage.cpp : Implementation of the CSerialPortPropPage property page class.

#include "stdafx.h"
#include "SerialPort.h"
#include "SerialPortPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CSerialPortPropPage, COlePropertyPage)

// Message map

BEGIN_MESSAGE_MAP(CSerialPortPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CSerialPortPropPage, "SERIALPORT.SerialPortPropPage.1",
	0xf9829640, 0x25ff, 0x422e, 0x89, 0x78, 0xad, 0x36, 0x21, 0x7d, 0xb2, 0x70)

// CSerialPortPropPage::CSerialPortPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CSerialPortPropPage

BOOL CSerialPortPropPage::CSerialPortPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_SERIALPORT_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CSerialPortPropPage::CSerialPortPropPage - Constructor

CSerialPortPropPage::CSerialPortPropPage() :
	COlePropertyPage(IDD, IDS_SERIALPORT_PPG_CAPTION)
{
}

// CSerialPortPropPage::DoDataExchange - Moves data between page and properties

void CSerialPortPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CSerialPortPropPage message handlers
