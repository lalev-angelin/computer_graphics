
// ComputerGraphics1.h : main header file for the ComputerGraphics1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CComputerGraphics1App:
// See ComputerGraphics1.cpp for the implementation of this class
//

class CComputerGraphics1App : public CWinApp
{
public:
	CComputerGraphics1App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CComputerGraphics1App theApp;
