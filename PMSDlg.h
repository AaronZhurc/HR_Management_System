// PMSDlg.h : header file
//

#if !defined(AFX_PMSDLG_H__E7A436A5_DAD7_41CD_836A_04475045DF98__INCLUDED_)
#define AFX_PMSDLG_H__E7A436A5_DAD7_41CD_836A_04475045DF98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPMSDlg dialog

class CPMSDlg : public CDialog
{
// Construction
public:
	CPMSDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPMSDlg)
	enum { IDD = IDD_PMS_DIALOG };
	CListCtrl	m_list;
	CComboBox	m_key;
	CString	m_value;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPMSDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPMSDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonShow();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonUpdate();
	afx_msg void OnButtonSearch();
	afx_msg void OnButtonDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PMSDLG_H__E7A436A5_DAD7_41CD_836A_04475045DF98__INCLUDED_)
