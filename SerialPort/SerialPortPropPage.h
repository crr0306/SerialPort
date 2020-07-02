#pragma once

// SerialPortPropPage.h : Declaration of the CSerialPortPropPage property page class.


// CSerialPortPropPage : See SerialPortPropPage.cpp for implementation.

class CSerialPortPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CSerialPortPropPage)
	DECLARE_OLECREATE_EX(CSerialPortPropPage)

// Constructor
public:
	CSerialPortPropPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_SERIALPORT };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};

