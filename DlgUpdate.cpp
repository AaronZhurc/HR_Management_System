// DlgUpdate.cpp : implementation file
//

#include "stdafx.h"
#include "PMS.h"
#include "DlgUpdate.h"
#include ".\\CAdo\\Ado.h"
#include "stdio.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgUpdate dialog


CDlgUpdate::CDlgUpdate(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgUpdate::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgUpdate)
	m_up_age = 0;
	m_up_name = _T("");
	m_up_res = _T("");
	m_up_wage = 0.0;
	m_up_value = 0;
	m_up_date = 0;
	m_up_no = _T("");
	//}}AFX_DATA_INIT
}


void CDlgUpdate::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgUpdate)
	DDX_Control(pDX, IDC_COMBO_PRO, m_up_pro);
	DDX_Control(pDX, IDC_COMBO_SEX, m_up_sex);
	DDX_Control(pDX, IDC_COMBO_DEPT, m_up_dept);
	DDX_Text(pDX, IDC_EDIT_UPDATE_AGE, m_up_age);
	DDX_Text(pDX, IDC_EDIT_UPDATE_NAME, m_up_name);
	DDX_Text(pDX, IDC_EDIT_UPDATE_RES, m_up_res);
	DDX_Text(pDX, IDC_EDIT_UPDATE_WAGE, m_up_wage);
	DDX_Text(pDX, IDC_EDIT_UPDATE_INPUT, m_up_value);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER, m_up_date);
	DDX_Text(pDX, IDC_STATIC_NO, m_up_no);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgUpdate, CDialog)
	//{{AFX_MSG_MAP(CDlgUpdate)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE_INPUT, OnButtonUpdateInput)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE_OK, OnButtonUpdateOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgUpdate message handlers

void CDlgUpdate::OnButtonUpdateInput() 
{
	// TODO: Add your control notification handler code here
	CAdo m_Ado;

	CString str_path,str_filePath,str_dbPath;
	GetModuleFileName(NULL,str_path.GetBufferSetLength(MAX_PATH+1),MAX_PATH+1);
	int nPos=str_path.ReverseFind(_T('\\'));
	str_filePath=str_path.Left(nPos+1);
	str_filePath+="\\staff.mdb";
	m_Ado.OnInitADOConn(str_filePath);

	CString sql,temp;
	UpdateData(true);
	sql.Format("select * from s where ");
	temp.Format("sno=%d",m_up_value);
	sql+=temp;
	m_Ado.GetRecordSet(sql);
	int nIndex;
	int m_y,m_m,m_d;
	
	if(!m_Ado.m_pRecordset->adoEOF){
		m_up_no=m_Ado.GetCollect("sno");
		m_up_name=m_Ado.GetCollect("sname");
		m_up_age=atoi(m_Ado.GetCollect("sage"));
		m_up_wage=atof(m_Ado.GetCollect("swage"));
		m_up_res=m_Ado.GetCollect("sres");
		nIndex=m_up_sex.SelectString(-1,m_Ado.GetCollect("ssex"));
		if(nIndex!=CB_ERR){
			m_up_sex.SetCurSel(nIndex);
		}
		nIndex=m_up_pro.SelectString(-1,m_Ado.GetCollect("spro"));
		if(nIndex!=CB_ERR){
			m_up_pro.SetCurSel(nIndex);
		}
		nIndex=m_up_dept.SelectString(-1,m_Ado.GetCollect("sdept"));
		if(nIndex!=CB_ERR){
			m_up_dept.SetCurSel(nIndex);
		}
		sscanf(m_Ado.GetCollect("sdate"),"%d-%d-%d",&m_y,&m_m,&m_d);
		CTime m_t(m_y,m_m,m_d,0,0,0);
		m_up_date=m_t;
		UpdateData(false);
	}
	m_Ado.ExitConnect();
}

void CDlgUpdate::OnButtonUpdateOk() 
{
	// TODO: Add your control notification handler code here
	CAdo m_Ado;

	CString str_path,str_filePath,str_dbPath;
	GetModuleFileName(NULL,str_path.GetBufferSetLength(MAX_PATH+1),MAX_PATH+1);
	int nPos=str_path.ReverseFind(_T('\\'));
	str_filePath=str_path.Left(nPos+1);
	str_filePath+="\\staff.mdb";
	m_Ado.OnInitADOConn(str_filePath);

	int m_y,m_m,m_d;
	int flag_exit=0;
	CString str_pro,str_sex,str_dept,str_date;
    CString temp;
	CString sql;
	UpdateData(true);

	m_up_pro.GetWindowText(str_pro);
	m_up_sex.GetWindowText(str_sex);
	m_up_dept.GetWindowText(str_dept);
	m_y=m_up_date.GetYear();
	m_m=m_up_date.GetMonth();
	m_d=m_up_date.GetDay();
	sql.Format("update s set sname=");
	temp.Format("'%s',sage=",m_up_name);
	sql+=temp;
	temp.Format("%d,ssex=",m_up_age);
	sql+=temp;
	temp.Format("'%s',sdept=",str_sex);
	sql+=temp;
	temp.Format("'%s',sres=",str_dept);
	sql+=temp;
	temp.Format("'%s',spro=",m_up_res);
	sql+=temp;
	temp.Format("'%s',swage=",str_pro);
	sql+=temp;
	temp.Format("%lf,sdate=",m_up_wage);
	sql+=temp;
	temp.Format("CDate('%d-%d-%d') where sno=",m_y,m_m,m_d);
	sql+=temp;
	temp.Format("%d",m_up_value);
	sql+=temp;
	if(m_Ado.ExecuteSQL(sql)==FALSE)
		flag_exit=1;
	m_Ado.ExitConnect();
	if(flag_exit==0)
		CDialog::OnOK();
}
