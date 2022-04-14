// CzhanghaoDlg.cpp: 实现文件
//

#include "pch.h"
#include "008.h"
#include "afxdialogex.h"
#include "CzhanghaoDlg.h"
#include "winsock.h"
#include "mysql.h"

// CzhanghaoDlg 对话框

IMPLEMENT_DYNAMIC(CzhanghaoDlg, CDialogEx)

CzhanghaoDlg::CzhanghaoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG92, pParent)
	, na1(_T(""))
	, na2(_T(""))
{

}
int a;
CzhanghaoDlg::~CzhanghaoDlg()
{
}

void CzhanghaoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, na1);
	DDX_Text(pDX, IDC_EDIT2, na2);
}


BEGIN_MESSAGE_MAP(CzhanghaoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CzhanghaoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CzhanghaoDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON2, &CzhanghaoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CzhanghaoDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CzhanghaoDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CzhanghaoDlg 消息处理程序


void CzhanghaoDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	GetDlgItem(IDC_EDIT1)->GetWindowText(na1);
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
		 mysql_query(&mysqlCon,"SET USER GBK"); 

	}
	CString select_sql_by_user1;
	select_sql_by_user1.Format("select id,name,zhuangtai from studentlogin where id = '%s'", na1);
	int ress = mysql_query(&mysqlCon, (char*)(LPCTSTR)select_sql_by_user1);
	if (ress == 0) //检测查询成功
	{
		res = mysql_store_result(&mysqlCon);
		if (mysql_num_rows(res) == 0) //查询结果为空
		{
			AfxMessageBox(_T("账号不存在"));
		}
		else
		{
			row = mysql_fetch_row(res);
			na2 = TEXT("编号：");
			na2 = na2 + row[0];
			na2 = na2 + TEXT("\r\n姓名：");
			na2 = na2 + row[1];
			na2 = na2 + TEXT("\r\n状态：");
			na2 = na2 + row[2];
			a = 1;
		}
	}
	else
	{
		AfxMessageBox(_T("访问失败!"));
	}
	UpdateData(FALSE);
}


	void CzhanghaoDlg::OnBnClickedButton5()
	{
		// TODO: 在此添加控件通知处理程序代码
		UpdateData(TRUE);
		GetDlgItem(IDC_EDIT1)->GetWindowText(na1);
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
			 mysql_query(&mysqlCon,"SET USER GBK"); 

		}
		CString select_sql_by_user1;
		select_sql_by_user1.Format("select id,name,zhuangtai from teacherlogin where id = '%s'", na1);
		int ress = mysql_query(&mysqlCon, (char*)(LPCTSTR)select_sql_by_user1);
		if (ress == 0) //检测查询成功
		{
			res = mysql_store_result(&mysqlCon);
			if (mysql_num_rows(res) == 0) //查询结果为空
			{
				AfxMessageBox(_T("账号不存在"));
			}
			else
			{
				row = mysql_fetch_row(res);
				na2 = TEXT("编号：");
				na2 = na2 + row[0];
				na2 = na2 + TEXT("\r\n姓名：");
				na2 = na2 + row[1];
				na2 = na2 + TEXT("\r\n状态：");
				na2 = na2 + row[2];
				a = 2;
			}
		}
		else
		{
			AfxMessageBox(_T("访问失败!"));
		}
		UpdateData(FALSE);
	}


		void CzhanghaoDlg::OnBnClickedButton2()
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
			if(a==1)
			sprintf_s(insert, "update studentlogin set zhuangtai = '1' where id = '%s' ", x);
			else if(a==2)
			sprintf_s(insert, "update teacherlogin set zhuangtai = '1' where id = '%s' ", x);
			AfxMessageBox(_T("已更改！"));
			if (mysql_query(&mysqlCon, insert) == 0)
			{
				UpdateData(FALSE);
			}
		}


		void CzhanghaoDlg::OnBnClickedButton3()
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
			if (a == 1)
				sprintf_s(insert, "update studentlogin set zhuangtai = '0' where id = '%s' ", x);
			else if (a == 2)
				sprintf_s(insert, "update teacherlogin set zhuangtai = '0' where id = '%s' ", x);
			AfxMessageBox(_T("已更改！"));
			if (mysql_query(&mysqlCon, insert) == 0)
			{
				UpdateData(FALSE);
			}
		}


		void CzhanghaoDlg::OnBnClickedButton4()
		{
			// TODO: 在此添加控件通知处理程序代码
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
				mysql_query(&mysqlCon, "SET USER GBK"); //设置字符集
			}
			GetDlgItem(IDC_EDIT1)->GetWindowText(na1);
			char* x = (char*)na1.GetBuffer();
			char insert[1000];
			if(a==1)
			sprintf_s(insert, "delete from studentlogin where name = \'%s'\ ", x);
			else if(a==2)
				sprintf_s(insert, "delete from teacherlogin where name = \'%s'\ ", x);
			if (mysql_query(&mysqlCon, insert) == 0)
			{
				AfxMessageBox(_T("删除成功!"));

			}
			else {
				AfxMessageBox(_T("删除失败!"));

			}
		}
