// CyemianDlg.cpp: 实现文件
//

#include "pch.h"
#include "008.h"
#include "afxdialogex.h"
#include "CyemianDlg.h"
#include "winsock.h"
#include "mysql.h"


// CyemianDlg 对话框

IMPLEMENT_DYNAMIC(CyemianDlg, CDialogEx)

CyemianDlg::CyemianDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG9, pParent)
	, na1(_T(""))
	, na2(_T(""))
{

}

CyemianDlg::~CyemianDlg()
{
}

void CyemianDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, na1);
	DDX_Text(pDX, IDC_EDIT2, na2);
}


BEGIN_MESSAGE_MAP(CyemianDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CyemianDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CyemianDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON4, &CyemianDlg::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT3, &CyemianDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDOK, &CyemianDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON5, &CyemianDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &CyemianDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &CyemianDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON1, &CyemianDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CyemianDlg 消息处理程序



void CyemianDlg::OnBnClickedButton4()
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
	select_sql_by_user1.Format("select id,name,sex,phone,grade,kemu,fee,zhuangtai from student where id = \'%s\'", na2);
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


void CyemianDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CyemianDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
void CyemianDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}void CyemianDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CyemianDlg::OnBnClickedButton5()
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
	select_sql_by_user1.Format("select id,name,sex,phone,grade,kemu,fee,zhuangtai from teacher where id = \'%s\'", na2);
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


void CyemianDlg::OnBnClickedButton3()
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
	GetDlgItem(IDC_EDIT2)->GetWindowText(na2);
	char* x = (char*)na2.GetBuffer();
	char insert[1000];
		
	sprintf_s(insert, "delete from student where name = \'%s'\ ", x);
	if (mysql_query(&mysqlCon, insert) == 0)
	{
		AfxMessageBox(_T("删除成功!"));

	}
	else {
		AfxMessageBox(_T("删除失败!"));

	}

}


void CyemianDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
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
	GetDlgItem(IDC_EDIT2)->GetWindowText(na2);
	char* x = (char*)na2.GetBuffer();
	char insert[1000];

	sprintf_s(insert, "delete from teacher where name = \'%s'\ ", x);
	if (mysql_query(&mysqlCon, insert) == 0)
	{
		AfxMessageBox(_T("删除成功!"));

	}
	else {
		AfxMessageBox(_T("删除失败!"));

	}
}


void CyemianDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}
