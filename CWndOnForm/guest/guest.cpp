// guest.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "guest.h"
#include <memory>
#include <utility>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CguestApp

BEGIN_MESSAGE_MAP(CguestApp, CWinApp)
END_MESSAGE_MAP()


// CguestApp construction

CguestApp::CguestApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CguestApp object

CguestApp theApp;


// CguestApp initialization

BOOL CguestApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

/** Stuff to be detached and/or deleted. */
using MFCStuff = std::pair<std::unique_ptr<CWnd>, std::unique_ptr<CStatic>>;

/** Attach MFC stuff to HWND from Windows.Forms */
extern "C" __declspec(dllexport) MFCStuff* PASCAL attach(HWND hwnd) {
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	auto w = std::make_unique<CWnd>();

	if (!w->Attach(hwnd)) { return nullptr; }

	// add some label
	CRect labelRect;
	w->GetClientRect(labelRect);

	labelRect.TopLeft().Offset(4, 4);

	auto label = std::make_unique<CStatic>();
	label->Create(_T("hello"), WS_CHILD | WS_VISIBLE, labelRect, w.get());

	auto pair = std::make_unique<MFCStuff>(std::move(w), std::move(label));

	return pair.release();
}

/** Detach and delete MFC stuff */
extern "C" __declspec(dllexport) void PASCAL detach(MFCStuff *p) {
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	auto pair = std::unique_ptr<MFCStuff>(p);
	pair->first->Detach();
}
