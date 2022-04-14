// CStudentRDlg.cpp: 实现文件
//

#include "pch.h"
#include "008.h"
#include "afxdialogex.h"
#include "CStudentRDlg.h"
#include "winsock.h"
#include "mysql.h"


// CStudentRDlg 对话框

IMPLEMENT_DYNAMIC(CStudentRDlg, CDialogEx)

CStudentRDlg::CStudentRDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG7, pParent)
	, user(_T(""))
	, pas(_T(""))
	, idd(_T(""))
{

}

CStudentRDlg::~CStudentRDlg()
{
}

void CStudentRDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, user);
	DDX_Text(pDX, IDC_EDIT2, pas);
	DDX_Text(pDX, IDC_EDIT3, idd);
}


BEGIN_MESSAGE_MAP(CStudentRDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStudentRDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CStudentRDlg 消息处理程序


void CStudentRDlg::OnBnClickedOk()
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
	sprintf_s(insert, "insert into studentlogin(id, name, pass) values (\'%s\',\'%s\', \'%s\')", z, x, y);
	if (mysql_query(&mysqlCon, insert) == 0)
	{
		AfxMessageBox(_T("添加成功!"));
		CDialog::OnCancel();

	}
	else {
		AfxMessageBox(_T("账号已存在!"));

	}

}
