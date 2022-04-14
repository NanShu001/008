// CLogin1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "008.h"
#include "afxdialogex.h"
#include "CLogin1Dlg.h"
#include "CStudentDlg.h"
#include "winsock.h"
#include "mysql.h"
#include "CStudentRDlg.h"

// CLogin1Dlg 对话框

IMPLEMENT_DYNAMIC(CLogin1Dlg, CDialogEx)

CLogin1Dlg::CLogin1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, user0(_T(""))
	, pas0(_T(""))
{

}

CLogin1Dlg::~CLogin1Dlg()
{
}

void CLogin1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, user0);
	DDX_Text(pDX, IDC_EDIT2, pas0);
}


BEGIN_MESSAGE_MAP(CLogin1Dlg, CDialogEx)
	ON_COMMAND(ID_32771, &CLogin1Dlg::On32771)
	ON_BN_CLICKED(IDOK, &CLogin1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CLogin1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, &CLogin1Dlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT1, &CLogin1Dlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CLogin1Dlg 消息处理程序


void CLogin1Dlg::On32771()
{
	// TODO: 在此添加命令处理程序代码
	
}


void CLogin1Dlg::OnBnClickedOk()
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
	select_sql_by_user.Format("select id, pass from studentlogin where id = \'%s\'", user0);
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
				CStudentDlg dlg;
				dlg.DoModal();
			}
			else
			{
				MessageBox(TEXT("密码错误!"));
			}
		}


	}

	
	
}


void CLogin1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CStudentRDlg dlg;
	dlg.DoModal();
}


void CLogin1Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CLogin1Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
