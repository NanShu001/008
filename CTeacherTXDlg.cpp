// CTeacherTXDlg.cpp: 实现文件
//

#include "pch.h"
#include "008.h"
#include "afxdialogex.h"
#include "CTeacherTXDlg.h"
#include "winsock.h"
#include "mysql.h"

// CTeacherTXDlg 对话框

IMPLEMENT_DYNAMIC(CTeacherTXDlg, CDialogEx)

CTeacherTXDlg::CTeacherTXDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG12, pParent)
	, na1(_T(""))
	, na2(_T(""))
	, na3(_T(""))
{

}

CTeacherTXDlg::~CTeacherTXDlg()
{
}

void CTeacherTXDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, na1);
	DDX_Text(pDX, IDC_EDIT2, na2);
	DDX_Text(pDX, IDC_EDIT3, na3);
}


BEGIN_MESSAGE_MAP(CTeacherTXDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTeacherTXDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CTeacherTXDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTeacherTXDlg 消息处理程序


void CTeacherTXDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	GetDlgItem(IDC_EDIT2)->GetWindowText(na2);
	const char name[] = "root";
	const char pswd[] = "111111";
	const char host[] = "localhost";
	const char table[] = "studentlogin";
	unsigned int port = 3306;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL mysqlCon;
	mysql_init(&mysqlCon);
	if (!mysql_real_connect(&mysqlCon, host, name, pswd, table, port, NULL, 0))
	{
		AfxMessageBox(_T("访问数据库失败!"));
	}
	else
	{
		// mysql_query(&mysqlCon,"SET USER GBK"); 设置字符集

	}
	CString select_sql_by_user1;
	select_sql_by_user1.Format("select id,name,pass,fee from teacherlogin where id = \'%s\'", na2);
	int ress = mysql_query(&mysqlCon, (char*)(LPCTSTR)select_sql_by_user1);
	if (ress == 0) //检测查询成功
	{
		res = mysql_store_result(&mysqlCon);
		if (mysql_num_rows(res) == 0) //查询结果为空
		{
			AfxMessageBox(_T("订单不存在"));
		}
		else
		{
			row = mysql_fetch_row(res);
			na3 = TEXT("id：");
			na3 = na3 +  row[0];
			na3 = na3 + TEXT("\r\n姓名：");
			na3 = na3 + row[1];
			na3 = na3 + TEXT("\r\n余额：");
			na3 = na3 + row[3];
		}


	}
	else
	{
		AfxMessageBox(_T("访问失败!"));
	}
	UpdateData(FALSE);
}


void CTeacherTXDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	GetDlgItem(IDC_EDIT1)->GetWindowText(na1);
	GetDlgItem(IDC_EDIT2)->GetWindowText(na2);
	const char name[] = "root";
	const char pswd[] = "111111";
	const char host[] = "localhost";
	const char table[] = "studentlogin";
	unsigned int port = 3306;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL mysqlCon;
	mysql_init(&mysqlCon);
	if (!mysql_real_connect(&mysqlCon, host, name, pswd, table, port, NULL, 0))
	{
		AfxMessageBox(_T("访问数据库失败!"));
	}
	else
	{
		// mysql_query(&mysqlCon,"SET USER GBK"); 设置字符集

	}
	char insert[1000];
	char* x = (char*)na1.GetBuffer();
	char* y = (char*)na2.GetBuffer();
	sprintf_s(insert, "update teacherlogin set fee = '%s' where id = '%s' ", x, y);
	if (mysql_query(&mysqlCon, insert) == 0)
	{
		UpdateData(FALSE);
		AfxMessageBox(_T("提现成功!"));
	}
}
