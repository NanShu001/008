// CTeacherXXDlg.cpp: 实现文件
//

#include "pch.h"
#include "008.h"
#include "afxdialogex.h"
#include "CTeacherXXDlg.h"
#include "winsock.h"
#include "mysql.h"

// CTeacherXXDlg 对话框

IMPLEMENT_DYNAMIC(CTeacherXXDlg, CDialogEx)

CTeacherXXDlg::CTeacherXXDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG10, pParent)
	, na1(_T(""))
	, na2(_T(""))
	, na3(_T(""))
	, na4(_T(""))
	, na5(_T(""))
	, na6(_T(""))
	, na7(_T(""))
{

}

CTeacherXXDlg::~CTeacherXXDlg()
{
}

void CTeacherXXDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, na1);
	DDX_Text(pDX, IDC_EDIT2, na2);
	DDX_Text(pDX, IDC_EDIT3, na3);
	DDX_Text(pDX, IDC_EDIT4, na4);
	DDX_Text(pDX, IDC_EDIT5, na5);
	DDX_Text(pDX, IDC_EDIT7, na6);
	DDX_Text(pDX, IDC_EDIT6, na7);
}


BEGIN_MESSAGE_MAP(CTeacherXXDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CTeacherXXDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTeacherXXDlg 消息处理程序


void CTeacherXXDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	//CDialogEx::OnOK();
	GetDlgItem(IDC_EDIT1)->GetWindowText(na1);
	GetDlgItem(IDC_EDIT2)->GetWindowText(na2);
	GetDlgItem(IDC_EDIT3)->GetWindowText(na3);
	GetDlgItem(IDC_EDIT4)->GetWindowText(na4);
	GetDlgItem(IDC_EDIT5)->GetWindowText(na5);
	GetDlgItem(IDC_EDIT6)->GetWindowText(na6);
	GetDlgItem(IDC_EDIT7)->GetWindowText(na7);
	const char name[] = "root";
	const char pswd[] = "111111";
	const char host[] = "localhost";
	const char table[] = "studentlogin";
	unsigned int port = 3306;
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL mysqlCon;
	if (na1.IsEmpty() || na2.IsEmpty()||na3.IsEmpty() || na4.IsEmpty()||na5.IsEmpty() || na6.IsEmpty()||na7.IsEmpty())
	{
		MessageBox(TEXT("不能为空!"));
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
	char* x1 = (char*)na1.GetBuffer();
	char* x2 = (char*)na2.GetBuffer();
	char* x3 = (char*)na3.GetBuffer();
	char* x4 = (char*)na4.GetBuffer();
	char* x5 = (char*)na5.GetBuffer();
	char* x6 = (char*)na6.GetBuffer();
	char* x7 = (char*)na7.GetBuffer();
	char insert[1000];
	sprintf_s(insert, "insert into teacher(id,name,sex,phone,grade,kemu,fee,zhuangtai) values (\'%s\', \'%s\', \'%s\', \'%s\', \'%s\', \'%s\', \'%s\', '0')", x1, x2,x3,x4,x5,x6,x7);
	if (mysql_query(&mysqlCon, insert) == 0)
	{
		AfxMessageBox(_T("添加成功!"));
		CDialog::OnCancel();

	}
	else {
		AfxMessageBox(_T("信息已存在!"));

	}


	}

