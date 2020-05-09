// ddrawYUV.h : main header file for the DDRAWYUV application
//

#if !defined(AFX_DDRAWYUV_H__312BD66D_52F7_4116_98C4_A95F8E327A46__INCLUDED_)
#define AFX_DDRAWYUV_H__312BD66D_52F7_4116_98C4_A95F8E327A46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDdrawYUVApp:
// See ddrawYUV.cpp for the implementation of this class
//

class CDdrawYUVApp : public CWinApp
{
public:
	CDdrawYUVApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDdrawYUVApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDdrawYUVApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDRAWYUV_H__312BD66D_52F7_4116_98C4_A95F8E327A46__INCLUDED_)
