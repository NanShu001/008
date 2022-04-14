// CTeacherJDDlg.cpp: 实现文件
//

#include "pch.h"
#include "008.h"
#include "afxdialogex.h"
#include "CTeacherJDDlg.h"
#include "winsock.h"
#include "mysql.h"

// CTeacherJDDlg 对话框

IMPLEMENT_DYNAMIC(CTeacherJDDlg, CDialogEx)

CTeacherJDDlg::CTeacherJDDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG14, pParent)
	, na1(_T(""))
	, na2(_T(""))
{

}

CTeacherJDDlg::~CTeacherJDDlg()
{
}

void CTeacherJDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, na1);
	DDX_Text(pDX, IDC_EDIT2, na2);
}


BEGIN_MESSAGE_MAP(CTeacherJDDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CTeacherJDDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CTeacherJDDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTeacherJDDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CTeacherJDDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTeacherJDDlg 消息处理程序

void CTeacherJDDlg::OnBnClickedButton3()
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
	GetDlgItem(IDC_EDIT2)->GetWindowText(na2);
	if (!mysql_real_connect(&mysqlCon, host, name, pswd, table, port, NULL, 0))
	{
		AfxMessageBox(_T("访问数据库失败!"));
	}
	else
	{
		// mysql_query(&mysqlCon,"SET USER GBK"); 设置字符集

	}
	CString select_sql_by_user1;
	select_sql_by_user1.Format("select id,name,sex,phone,grade,kemu,fee,zhuangtai from student where id = '%s'", na2);	
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
			na1 = TEXT("编号：");
			na1 = na1 + row[0];
			na1 = na1 + TEXT("\r\n姓名：");
			na1 = na1 + row[1];
			na1 = na1 + TEXT("\r\n性别：");
			na1 = na1 + row[2];
			na1 = na1 + TEXT("\r\n手机号：");
			na1 = na1 + row[3];
			na1 = na1 + TEXT("\r\n年级：");
			na1 = na1 + row[4];
			na1 = na1 + TEXT("\r\n科目：");
			na1 = na1 + row[5];
			na1 = na1 + TEXT("\r\n费用：");
			na1 = na1 + row[6];
			na1 = na1 + TEXT("\r\n状态：");
			na1 = na1 + row[7];
		}


	}
	else
	{
		AfxMessageBox(_T("访问失败!"));
	}
	UpdateData(FALSE);
}


void CTeacherJDDlg::OnBnClickedButton1()
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
		// mysql_query(&mysqlCon,"SET USER GBK"); 设置字符集

	}
	CString select_sql_by_user1;
	select_sql_by_user1.Format("select id,name,sex,phone,grade,kemu,fee,zhuangtai from student where grade = '%s'", na2);	int ress = mysql_query(&mysqlCon, (char*)(LPCTSTR)select_sql_by_user1);
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
			na1 = TEXT("编号：");
			na1 = na1 + row[0];
			na1 = na1 + TEXT("\r\n姓名：");
			na1 = na1 + row[1];
			na1 = na1 + TEXT("\r\n状态：");
			na1 = na1 + row[2];
			na1 = na1 + TEXT("\r\n姓名：");
			na1 = na1 + row[3];
			na1 = na1 + TEXT("\r\n状态：");
			na1 = na1 + row[4];
			na1 = na1 + TEXT("\r\n姓名：");
			na1 = na1 + row[5];
			na1 = na1 + TEXT("\r\n状态：");
			na1 = na1 + row[6];
		}


	}
	else
	{
		AfxMessageBox(_T("访问失败!"));
	}
	UpdateData(FALSE);
}


void CTeacherJDDlg::OnBnClickedButton2()
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
		// mysql_query(&mysqlCon,"SET USER GBK"); 设置字符集

	}
	CString select_sql_by_user1;
	select_sql_by_user1.Format("select id,name,sex,phone,grade,kemu,fee,zhuangtai from student where id = '%s'", na2);
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
			na1 = TEXT("编号：");
			na1 = na1 + row[0];
			na1 = na1 + TEXT("\r\n姓名：");
			na1 = na1 + row[1];
			na1 = na1 + TEXT("\r\n状态：");
			na1 = na1 + row[2];
			na1 = na1 + TEXT("\r\n姓名：");
			na1 = na1 + row[3];
			na1 = na1 + TEXT("\r\n状态：");
			na1 = na1 + row[4];
			na1 = na1 + TEXT("\r\n姓名：");
			na1 = na1 + row[5];
			na1 = na1 + TEXT("\r\n状态：");
			na1 = na1 + row[6];
		}


	}
	else
	{
		AfxMessageBox(_T("访问失败!"));
	}
	UpdateData(FALSE);
}


void CTeacherJDDlg::OnBnClickedOk()
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
		// mysql_query(&mysqlCon,"SET USER GBK"); 设置字符集

	}
	CString select_sql_by_user1;
	select_sql_by_user1.Format("select id,name,sex,phone,grade,kemu,fee,zhuangtai from student where id = '%s'" , na2);
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
			char insert[1000];
			sprintf_s(insert, "insert into dingdan(id, name,price,zhuangtai) values (\'%s\', \'%s\',\'%s'\,'-1')", row[0],row[1],row[6]);
			if (mysql_query(&mysqlCon, insert) == 0)
			AfxMessageBox(_T("订单已接受！"));
			sprintf_s(insert, "update student set zhuangtai = '1' where id =  '%s'",row[0]);
			if (mysql_query(&mysqlCon, insert) == 0);
		}


	}
	else
	{
		AfxMessageBox(_T("访问失败!"));
	}
	UpdateData(FALSE);
}
