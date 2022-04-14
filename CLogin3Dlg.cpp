// CLogin3Dlg.cpp: 实现文件
//

#include "pch.h"
#include "008.h"
#include "afxdialogex.h"
#include "CLogin3Dlg.h"
#include "CAdminDlg.h"


// CLogin3Dlg 对话框

IMPLEMENT_DYNAMIC(CLogin3Dlg, CDialogEx)

CLogin3Dlg::CLogin3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, user2(_T(""))
	, pas2(_T(""))
{

}

CLogin3Dlg::~CLogin3Dlg()
{
}

void CLogin3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, user2);
	DDX_Text(pDX, IDC_EDIT2, pas2);
}


BEGIN_MESSAGE_MAP(CLogin3Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLogin3Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CLogin3Dlg 消息处理程序


void CLogin3Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (user2.IsEmpty() || pas2.IsEmpty()) {
		MessageBox(TEXT("用户名或密码不能为空"));
	}
	else if (user2 == "1" && pas2 == "1") {
		CDialog::OnCancel();
		CAdminDlg dlg;
		dlg.DoModal();

	}
	else {
		MessageBox(TEXT("用户名或密码错误"));
	}
	
}
