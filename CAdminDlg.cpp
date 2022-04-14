// CAdminDlg.cpp: 实现文件
//

#include "pch.h"
#include "008.h"
#include "afxdialogex.h"
#include "CAdminDlg.h"
#include "CyemianDlg.h"
#include "CzhifuDlg.h"
#include "CzhanghaoDlg.h"

// CAdminDlg 对话框

IMPLEMENT_DYNAMIC(CAdminDlg, CDialogEx)

CAdminDlg::CAdminDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

CAdminDlg::~CAdminDlg()
{
}

void CAdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAdminDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAdminDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CAdminDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAdminDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAdminDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CAdminDlg 消息处理程序


void CAdminDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CAdminDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CyemianDlg dlg;
	dlg.DoModal();
}


void CAdminDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CzhifuDlg dlg;
	dlg.DoModal();
}


void CAdminDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	CzhanghaoDlg dlg;
	dlg.DoModal();
}
