// InitAppDlg.h : main header file for the InitAppDlg DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CInitAppDlgApp
// See InitAppDlg.cpp for the implementation of this class
//

class CInitAppDlgApp : public CWinApp
{
public:
	CInitAppDlgApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
