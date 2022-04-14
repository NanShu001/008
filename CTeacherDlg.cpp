// CTeacherDlg.cpp: 实现文件
//

#include "pch.h"
#include "008.h"
#include "afxdialogex.h"
#include "CTeacherDlg.h"
#include "CTeacherJDDlg.h"
#include "CTeacherTXDlg.h"
#include "CTeacherXXDlg.h"

// CTeacherDlg 对话框

IMPLEMENT_DYNAMIC(CTeacherDlg, CDialogEx)

CTeacherDlg::CTeacherDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

CTeacherDlg::~CTeacherDlg()
{
}

void CTeacherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTeacherDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CTeacherDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CTeacherDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CTeacherDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CTeacherDlg 消息处理程序


void CTeacherDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CTeacherJDDlg dlg;
	dlg.DoModal();
}


void CTeacherDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CTeacherXXDlg dlg;
	dlg.DoModal();
}


void CTeacherDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CTeacherTXDlg dlg;
	dlg.DoModal();
}
