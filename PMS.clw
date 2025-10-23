; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgUpdate
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PMS.h"

ClassCount=5
Class1=CPMSApp
Class2=CPMSDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PMS_DIALOG
Resource4=IDD_DIALOG_ADD
Class4=CDlgAdd
Class5=CDlgUpdate
Resource5=IDD_DIALOG_UPDATE

[CLS:CPMSApp]
Type=0
HeaderFile=PMS.h
ImplementationFile=PMS.cpp
Filter=N

[CLS:CPMSDlg]
Type=0
HeaderFile=PMSDlg.h
ImplementationFile=PMSDlg.cpp
Filter=D
LastObject=IDC_EDIT_VALUE
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=PMSDlg.h
ImplementationFile=PMSDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PMS_DIALOG]
Type=1
Class=CPMSDlg
ControlCount=11
Control1=IDC_LIST,SysListView32,1350631425
Control2=IDC_BUTTON_SHOW,button,1342242816
Control3=IDC_BUTTON_UPDATE,button,1342242816
Control4=IDC_STATIC,button,1342177287
Control5=IDC_BUTTON_ADD,button,1342242816
Control6=IDC_COMBO_KEY,combobox,1344340226
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_VALUE,edit,1350631552
Control10=IDC_BUTTON_SEARCH,button,1342242816
Control11=IDC_BUTTON_DELETE,button,1342242816

[DLG:IDD_DIALOG_ADD]
Type=1
Class=CDlgAdd
ControlCount=19
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_ADD_NO,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_ADD_NAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_ADD_AGE,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_ADD_WAGE,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT_ADD_RES,edit,1350631552
Control14=IDC_BUTTON_ADDOK,button,1342242816
Control15=IDC_STATIC,static,1342308352
Control16=IDC_COMBO_SEX,combobox,1344340226
Control17=IDC_DATETIMEPICKER,SysDateTimePick32,1342242848
Control18=IDC_COMBO_DEPT,combobox,1344340226
Control19=IDC_COMBO_PRO,combobox,1344340226

[DLG:IDD_DIALOG_UPDATE]
Type=1
Class=CDlgUpdate
ControlCount=23
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_UPDATE_NAME,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_UPDATE_AGE,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_UPDATE_WAGE,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_UPDATE_RES,edit,1350631552
Control13=IDC_BUTTON_UPDATE_OK,button,1342242816
Control14=IDC_STATIC,button,1342177287
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDIT_UPDATE_INPUT,edit,1350631552
Control17=IDC_BUTTON_UPDATE_INPUT,button,1342242816
Control18=IDC_STATIC,static,1342308352
Control19=IDC_COMBO_SEX,combobox,1344340226
Control20=IDC_COMBO_DEPT,combobox,1344340226
Control21=IDC_COMBO_PRO,combobox,1344340226
Control22=IDC_DATETIMEPICKER,SysDateTimePick32,1342242848
Control23=IDC_STATIC_NO,static,1342308352

[CLS:CDlgAdd]
Type=0
HeaderFile=DlgAdd.h
ImplementationFile=DlgAdd.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_ADD_SEX
VirtualFilter=dWC

[CLS:CDlgUpdate]
Type=0
HeaderFile=DlgUpdate.h
ImplementationFile=DlgUpdate.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_UPDATE_NO
VirtualFilter=dWC

