#if !defined(AFX_DLGADD_H__47320ECE_1404_441D_AE21_D4056BB8DD79__INCLUDED_)
#define AFX_DLGADD_H__47320ECE_1404_441D_AE21_D4056BB8DD79__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAdd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgAdd dialog

class CDlgAdd : public CDialog
{
// Construction
public:
	CDlgAdd(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgAdd)
	enum { IDD = IDD_DIALOG_ADD };
	CComboBox	m_add_sex;
	CComboBox	m_add_pro;
	CComboBox	m_add_dept;
	int		m_add_age;
	CString	m_add_name;
	int		m_add_no;
	double	m_add_wage;
	CTime	m_add_date;
	CString	m_add_res;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAdd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgAdd)
	afx_msg void OnButtonAddok();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGADD_H__47320ECE_1404_441D_AE21_D4056BB8DD79__INCLUDED_)
