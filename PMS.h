// PMS.h : main header file for the PMS application
//

#if !defined(AFX_PMS_H__0A75400B_BB74_4E49_987E_5C669A93340C__INCLUDED_)
#define AFX_PMS_H__0A75400B_BB74_4E49_987E_5C669A93340C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPMSApp:
// See PMS.cpp for the implementation of this class
//

class CPMSApp : public CWinApp
{
public:
	CPMSApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPMSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPMSApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PMS_H__0A75400B_BB74_4E49_987E_5C669A93340C__INCLUDED_)
