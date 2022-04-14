// CLogin2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "008.h"
#include "afxdialogex.h"
#include "CLogin2Dlg.h"
#include "CTeacherRDlg.h"
#include "winsock.h"
#include "mysql.h"
#include "CTeacherDlg.h"

IMPLEMENT_DYNAMIC(CLogin2Dlg, CDialogEx)

CLogin2Dlg::CLogin2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, user0(_T(""))
	, pas0(_T(""))
{

}

CLogin2Dlg::~CLogin2Dlg()
{
}

void CLogin2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, user0);
	DDX_Text(pDX, IDC_EDIT2, pas0);
}


BEGIN_MESSAGE_MAP(CLogin2Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CLogin2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CLogin2Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CLogin2Dlg 消息处理程序


void CLogin2Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CTeacherRDlg dlg;
	dlg.DoModal();
}


void CLogin2Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	//CDialogEx::OnOK();
	GetDlgItem(IDC_EDIT1)->GetWindowText(user0);
	GetDlgItem(IDC_EDIT2)->GetWindowText(pas0);
	const char name[] = "root";
	const char pswd[] = "111111";
	const char host[] = "localhost";
	const char table[] = "studentlogin";
	unsigned int port = 3306;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL mysqlCon;
	if (user0.IsEmpty() || pas0.IsEmpty())
	{
		MessageBox(TEXT("用户名或密码不能为空!"));
		user0.Empty();
		pas0.Empty();
	}

	mysql_init(&mysqlCon);
	if (!mysql_real_connect(&mysqlCon, host, name, pswd, table, port, NULL, 0))
	{
		AfxMessageBox(_T("访问数据库失败!"));
	}
	else
	{
		// mysql_query(&mysqlCon,"SET USER GBK"); 设置字符集

	}

	CString select_sql_by_user;
	select_sql_by_user.Format("select id, pass from teacherlogin where id = \'%s\'", user0);
	int ress = mysql_query(&mysqlCon, (char*)(LPCTSTR)select_sql_by_user);
	if (ress == 0) //检测查询成功
	{
		res = mysql_store_result(&mysqlCon);
		if (mysql_num_rows(res) == 0) //查询结果为空
		{
			AfxMessageBox(_T("学生不存在"));
		}
		else
		{

			row = mysql_fetch_row(res);
			if (pas0 == row[1])
			{
				MessageBox(TEXT("登录成功!"));
				CDialog::OnCancel();
				CTeacherDlg dlg;
				dlg.DoModal();
			}
			else
			{
				MessageBox(TEXT("密码错误!"));
			}
		}


	}
}
