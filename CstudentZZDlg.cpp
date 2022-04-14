// CstudentZZDlg.cpp: 实现文件
//

#include "pch.h"
#include "008.h"
#include "afxdialogex.h"
#include "CstudentZZDlg.h"
#include "winsock.h"
#include "mysql.h"

// CstudentZZDlg 对话框

IMPLEMENT_DYNAMIC(CstudentZZDlg, CDialogEx)

CstudentZZDlg::CstudentZZDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG114, pParent)
	, na1(_T(""))
	, na2(_T(""))
{

}

CstudentZZDlg::~CstudentZZDlg()
{
}

void CstudentZZDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, na1);
	DDX_Text(pDX, IDC_EDIT2, na2);
}


BEGIN_MESSAGE_MAP(CstudentZZDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CstudentZZDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CstudentZZDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CstudentZZDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDOK, &CstudentZZDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CstudentZZDlg 消息处理程序


void CstudentZZDlg::OnBnClickedButton1()
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
	select_sql_by_user1.Format("select id,name,price,zhuangtai from dingdan where id = '%s'", na1);
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
			na2 = TEXT("订单编号：");
			na2 = na2 + row[0];
			na2 = na2 + TEXT("\r\n收款人：");
			na2 = na2 + row[1];
			na2 = na2 + TEXT("\r\n金额：");
			na2 = na2 + row[2];
			na2 = na2 + TEXT("\r\n状态：");
			na2 = na2 + row[3];
			na2 = na2 + TEXT("\r\n（-1为未支付，0为待确认,1为已支付");
		}


	}
	else
	{
		AfxMessageBox(_T("访问失败!"));
	}
	UpdateData(FALSE);
}


void CstudentZZDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
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
		mysql_query(&mysqlCon, "SET USER GBK");

	}

	GetDlgItem(IDC_EDIT1)->GetWindowText(na1);
	char* x = (char*)na1.GetBuffer();
	char insert[1000];
	sprintf_s(insert, "update dingdan set zhuangtai = '0' where id = '%s' ", x);
	AfxMessageBox(_T("已支付！"));
	if (mysql_query(&mysqlCon, insert) == 0)
	{
		UpdateData(FALSE);
	}
}


void CstudentZZDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CstudentZZDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
