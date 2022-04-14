// CTeacherRDlg.cpp: 实现文件
//

#include "pch.h"
#include "008.h"
#include "afxdialogex.h"
#include "CTeacherRDlg.h"
#include "winsock.h"
#include "mysql.h"

// CTeacherRDlg 对话框

IMPLEMENT_DYNAMIC(CTeacherRDlg, CDialogEx)

CTeacherRDlg::CTeacherRDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG8, pParent)
	, user(_T(""))
	, pas(_T(""))
	, idd(_T(""))
{

}

CTeacherRDlg::~CTeacherRDlg()
{
}

void CTeacherRDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, user);
	DDX_Text(pDX, IDC_EDIT2, pas);
	DDX_Text(pDX, IDC_EDIT3, idd);
}


BEGIN_MESSAGE_MAP(CTeacherRDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CTeacherRDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CTeacherRDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CTeacherRDlg 消息处理程序


void CTeacherRDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	UpdateData(TRUE);
	GetDlgItem(IDC_EDIT1)->GetWindowText(user);
	GetDlgItem(IDC_EDIT2)->GetWindowText(pas);
	GetDlgItem(IDC_EDIT3)->GetWindowText(idd);
	const char name[] = "root";
	const char pswd[] = "111111";
	const char host[] = "localhost";
	const char table[] = "studentlogin";
	unsigned int port = 3306;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL mysqlCon;
	mysql_init(&mysqlCon);
	mysql_init(&mysqlCon);
	if (!mysql_real_connect(&mysqlCon, host, name, pswd, table, port, NULL, 0))
	{
		AfxMessageBox(_T("访问数据库失败!"));
	}
	else
	{
		mysql_query(&mysqlCon, "SET USER GBK"); //设置字符集
	}
	char* x = (char*)user.GetBuffer();
	char* y = (char*)pas.GetBuffer();
	char* z = (char*)idd.GetBuffer();
	UpdateData(TRUE);
	if (user.IsEmpty() || pas.IsEmpty())
	{
		MessageBox(TEXT("用户名或密码不能为空!"));
		user.Empty();
		pas.Empty();
		return;
	}
	char insert[1000];
	sprintf_s(insert, "insert into teacherlogin(id, name,pass) values (\'%s\', \'%s\',\'%s\')", z, x, y);
	if (mysql_query(&mysqlCon, insert) == 0)
	{
		AfxMessageBox(_T("添加成功!"));
		CDialog::OnCancel();

	}
	else {
		AfxMessageBox(_T("账号已存在!"));

	}
}


void CTeacherRDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
