// guest.h : main header file for the guest DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CguestApp
// See guest.cpp for the implementation of this class
//

class CguestApp : public CWinApp
{
public:
	CguestApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
