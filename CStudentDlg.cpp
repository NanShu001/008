// CStudentDlg.cpp: 实现文件
//

#include "pch.h"
#include "008.h"
#include "afxdialogex.h"
#include "CStudentDlg.h"
#include "CstudentJDDlg.h"
#include "CstudentXXDlg.h"
#include "CstudentZZDlg.h"
#include "CstudentCCDlg.h"


// CStudentDlg 对话框

IMPLEMENT_DYNAMIC(CStudentDlg, CDialogEx)

CStudentDlg::CStudentDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

CStudentDlg::~CStudentDlg()
{
}

void CStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStudentDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStudentDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CStudentDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CStudentDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CStudentDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CStudentDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CStudentDlg 消息处理程序


void CStudentDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CStudentDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CstudentXXDlg dlg;
	dlg.DoModal();
}


void CStudentDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CstudentJDDlg dlg;
	dlg.DoModal();
}


void CStudentDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CstudentZZDlg dlg;
	dlg.DoModal();
}


void CStudentDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CstudentCCDlg dlg;
	dlg.DoModal();
}
