#if !defined(AFX_DLGUPDATE_H__D7735331_7FD4_42FF_A943_CFDB653BCB10__INCLUDED_)
#define AFX_DLGUPDATE_H__D7735331_7FD4_42FF_A943_CFDB653BCB10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgUpdate.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgUpdate dialog

class CDlgUpdate : public CDialog
{
// Construction
public:
	CDlgUpdate(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgUpdate)
	enum { IDD = IDD_DIALOG_UPDATE };
	CComboBox	m_up_pro;
	CComboBox	m_up_sex;
	CComboBox	m_up_dept;
	int		m_up_age;
	CString	m_up_name;
	CString	m_up_res;
	double	m_up_wage;
	int		m_up_value;
	CTime	m_up_date;
	CString	m_up_no;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgUpdate)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgUpdate)
	afx_msg void OnButtonUpdateInput();
	afx_msg void OnButtonUpdateOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGUPDATE_H__D7735331_7FD4_42FF_A943_CFDB653BCB10__INCLUDED_)
