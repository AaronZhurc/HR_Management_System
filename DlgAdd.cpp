// DlgAdd.cpp : implementation file
//

#include "stdafx.h"
#include "PMS.h"
#include "DlgAdd.h"
#include ".\\CAdo\\Ado.h"
#include "stdio.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgAdd dialog


CDlgAdd::CDlgAdd(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAdd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgAdd)
	m_add_age = 0;
	m_add_name = _T("");
	m_add_no = 0;
	m_add_wage = 0.0;
	m_add_date = 0;
	m_add_res = _T("");
	//}}AFX_DATA_INIT
}


void CDlgAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAdd)
	DDX_Control(pDX, IDC_COMBO_SEX, m_add_sex);
	DDX_Control(pDX, IDC_COMBO_PRO, m_add_pro);
	DDX_Control(pDX, IDC_COMBO_DEPT, m_add_dept);
	DDX_Text(pDX, IDC_EDIT_ADD_AGE, m_add_age);
	DDX_Text(pDX, IDC_EDIT_ADD_NAME, m_add_name);
	DDX_Text(pDX, IDC_EDIT_ADD_NO, m_add_no);
	DDX_Text(pDX, IDC_EDIT_ADD_WAGE, m_add_wage);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER, m_add_date);
	DDX_Text(pDX, IDC_EDIT_ADD_RES, m_add_res);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgAdd, CDialog)
	//{{AFX_MSG_MAP(CDlgAdd)
	ON_BN_CLICKED(IDC_BUTTON_ADDOK, OnButtonAddok)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAdd message handlers

void CDlgAdd::OnButtonAddok() 
{
	// TODO: Add your control notification handler code here
	CString str_name,str_sex,str_dept,str_pro,str_res,str_date;
	CString sql,temp;
	int m_no,m_age,m_y,m_m,m_d;
	int flag_exit=0;
	double m_wage;
	CAdo m_Ado;

	CString str_path,str_filePath,str_dbPath;
	GetModuleFileName(NULL,str_path.GetBufferSetLength(MAX_PATH+1),MAX_PATH+1);
	int nPos=str_path.ReverseFind(_T('\\'));
	str_filePath=str_path.Left(nPos+1);
	str_filePath+="\\staff.mdb";
	m_Ado.OnInitADOConn(str_filePath);

	UpdateData(true);
	str_name=m_add_name;
	m_add_pro.GetWindowText(str_pro);
	m_add_sex.GetWindowText(str_sex);
	m_add_dept.GetWindowText(str_dept);
	str_res=m_add_res;
	m_no=m_add_no;
	m_age=m_add_age;
	m_wage=m_add_wage;
	m_y=m_add_date.GetYear();
	m_m=m_add_date.GetMonth();
	m_d=m_add_date.GetDay();
	sql="insert into s (sno,sname,ssex,sdept,sage,sdate,swage,spro,sres) values(";
	temp.Format("%d,'%s','%s','%s',%d,CDate('%d-%d-%d'),%lf,'%s','%s')",m_no,str_name,str_sex,str_dept,m_age,m_y,m_m,m_d,m_wage,str_pro,str_res);
	sql+=temp;
	if(m_Ado.ExecuteSQL(sql)!=FALSE){
	}
		flag_exit=1;
	m_Ado.ExitConnect();
	if(flag_exit==0)
		CDialog::OnOK();
}
