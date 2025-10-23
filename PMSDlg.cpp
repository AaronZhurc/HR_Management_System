// PMSDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PMS.h"
#include "PMSDlg.h"
#include ".\\CAdo\\Ado.h"
#include "DlgAdd.h"
#include "DlgUpdate.h"
#include "Time.h"
#include "stdio.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPMSDlg dialog

CPMSDlg::CPMSDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPMSDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPMSDlg)
	m_value = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPMSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPMSDlg)
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_COMBO_KEY, m_key);
	DDX_Text(pDX, IDC_EDIT_VALUE, m_value);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPMSDlg, CDialog)
	//{{AFX_MSG_MAP(CPMSDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SHOW, OnButtonShow)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPMSDlg message handlers

BOOL CPMSDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	int nColum=-1;
	m_list.InsertColumn(++nColum,"职工编号",LVCFMT_LEFT,60,0);
	m_list.InsertColumn(++nColum,"职工姓名",LVCFMT_LEFT,60,0);
	m_list.InsertColumn(++nColum,"职工性别",LVCFMT_LEFT,60,0);
	m_list.InsertColumn(++nColum,"所在部门",LVCFMT_LEFT,60,0);
	m_list.InsertColumn(++nColum,"职工年龄",LVCFMT_LEFT,60,0);
	m_list.InsertColumn(++nColum,"工作时间",LVCFMT_LEFT,60,0);
	m_list.InsertColumn(++nColum,"基本工资",LVCFMT_LEFT,60,0);
	m_list.InsertColumn(++nColum,"职称",LVCFMT_LEFT,60,0);
	m_list.InsertColumn(++nColum,"简历",LVCFMT_LEFT,60,0);
	
    m_list.ModifyStyle(0,LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP);

	m_list.SetTextColor(RGB(255,0,0));
	DWORD dwStyle=m_list.GetStyle();
	dwStyle|=LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_SHOWSELALWAYS;
	m_list.SetExtendedStyle(dwStyle);
	m_list.SetBkColor(RGB(240,247,233));
	m_list.SetTextBkColor(RGB(240,247,233));


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPMSDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPMSDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPMSDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPMSDlg::OnButtonShow() 
{
	// TODO: Add your control notification handler code here
	int nItem=-1;
	int i;
	CAdo m_Ado;

	CString str_path,str_filePath,str_dbPath;
	GetModuleFileName(NULL,str_path.GetBufferSetLength(MAX_PATH+1),MAX_PATH+1);
	int nPos=str_path.ReverseFind(_T('\\'));
	str_filePath=str_path.Left(nPos+1);
	str_filePath+="\\staff.mdb";
	m_Ado.OnInitADOConn(str_filePath);

	CString no,name,sex,dept,age,date,wage,pro,res,temp;
	CString sql,str;
	sql.Format("select * from s");
	m_Ado.GetRecordSet(sql);
	m_list.DeleteAllItems();
	while(!m_Ado.m_pRecordset->adoEOF){
		nItem++;
		no=m_Ado.GetCollect("sno");
		name=m_Ado.GetCollect("sname");
		sex=m_Ado.GetCollect("ssex");
		dept=m_Ado.GetCollect("sdept");
		age=m_Ado.GetCollect("sage");
		date=m_Ado.GetCollect("sdate");
		wage=m_Ado.GetCollect("swage");
		pro=m_Ado.GetCollect("spro");
		res=m_Ado.GetCollect("sres");
		m_list.InsertItem(nItem,no);
		m_list.SetItemText(nItem,1,name);
		m_list.SetItemText(nItem,2,sex);
		m_list.SetItemText(nItem,3,dept);
		m_list.SetItemText(nItem,4,age);
		m_list.SetItemText(nItem,5,date);
		m_list.SetItemText(nItem,6,wage);
		m_list.SetItemText(nItem,7,pro);
		m_list.SetItemText(nItem,8,res);
		m_Ado.m_pRecordset->MoveNext();
	}
	str.Format("共%d条记录",m_list.GetItemCount());
	AfxMessageBox(str);
	m_Ado.ExitConnect();
	UpdateData(false);
}

void CPMSDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	CDlgAdd dlg;
	dlg.DoModal();
}

void CPMSDlg::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	CDlgUpdate dlg;
	dlg.DoModal();
}

void CPMSDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	int nItem=-1;
	CAdo m_Ado;

	CString str_path,str_filePath,str_dbPath;
	GetModuleFileName(NULL,str_path.GetBufferSetLength(MAX_PATH+1),MAX_PATH+1);
	int nPos=str_path.ReverseFind(_T('\\'));
	str_filePath=str_path.Left(nPos+1);
	str_filePath+="\\staff.mdb";
	m_Ado.OnInitADOConn(str_filePath);

	CString no,name,sex,dept,age,date,wage,pro,res,temp;
	CString sql,str,key;
	try{
		UpdateData(true);
		sql.Format("select * from s where ");
		m_key.GetWindowText(key);
		if(!key.Compare("职工编号"))
			temp.Format("sno=%d",atoi(m_value));
		else if(!key.Compare("职工姓名"))
			temp.Format("sname='%s'",m_value);
		else if(!key.Compare("职工性别"))
			temp.Format("ssex='%s'",m_value);
		else if(!key.Compare("所在部门"))
			temp.Format("sdept='%s'",m_value);
		else if(!key.Compare("职工年龄"))
			temp.Format("sage=%d",atoi(m_value));
		else if(!key.Compare("工作时间")){
			int m_y,m_m,m_d;
			sscanf(m_value,"%d-%d-%d",&m_y,&m_m,&m_d);
			temp.Format("sdate=CDate('%d-%d-%d')",m_y,m_m,m_d);
		}
		else if(!key.Compare("基本工资"))
			temp.Format("swage=%lf",atof(m_value));
		else if(!key.Compare("职称"))
			temp.Format("spro='%s'",m_value);
		else if(!key.Compare("简历"))
			temp.Format("sres='%s'",m_value);
		sql+=temp;
		m_Ado.GetRecordSet(sql);
		m_list.DeleteAllItems();
		
		while(!m_Ado.m_pRecordset->adoEOF){
			nItem++;
			no=m_Ado.GetCollect("sno");
			name=m_Ado.GetCollect("sname");
			sex=m_Ado.GetCollect("ssex");
			dept=m_Ado.GetCollect("sdept");
			age=m_Ado.GetCollect("sage");
			date=m_Ado.GetCollect("sdate");
			wage=m_Ado.GetCollect("swage");
			pro=m_Ado.GetCollect("spro");
			res=m_Ado.GetCollect("sres");
			m_list.InsertItem(nItem,no);
			m_list.SetItemText(nItem,1,name);
			m_list.SetItemText(nItem,2,sex);
			m_list.SetItemText(nItem,3,dept);
			m_list.SetItemText(nItem,4,age);
			m_list.SetItemText(nItem,5,date);
			m_list.SetItemText(nItem,6,wage);
			m_list.SetItemText(nItem,7,pro);
			m_list.SetItemText(nItem,8,res);
			m_Ado.m_pRecordset->MoveNext();
		}
		str.Format("共%d条记录",m_list.GetItemCount());
		AfxMessageBox(str);
	}catch(...){
		OnButtonShow();
	}
	m_Ado.ExitConnect();
	UpdateData(false);
}

void CPMSDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	CAdo m_Ado;

	CString str_path,str_filePath,str_dbPath;
	GetModuleFileName(NULL,str_path.GetBufferSetLength(MAX_PATH+1),MAX_PATH+1);
	int nPos=str_path.ReverseFind(_T('\\'));
	str_filePath=str_path.Left(nPos+1);
	str_filePath+="\\staff.mdb";
	m_Ado.OnInitADOConn(str_filePath);

	CString temp;
	CString sql,str,key;
	UpdateData(true);
	int i;

	for(i=0;i<m_list.GetItemCount();i++){
		if(m_list.GetCheck(i)){
			str=m_list.GetItemText(i,0);
			sql.Format("delete from s where ");
			temp.Format("sno=%s",str);
			sql+=temp;
			m_Ado.GetRecordSet(sql);
		}
	}	
	m_Ado.ExitConnect();
	OnButtonShow();
}

/*
笔记：
删除：点击删除
日期控件的使用
下拉框选择性别、职称、部门等
*/
