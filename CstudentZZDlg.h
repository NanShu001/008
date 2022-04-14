#pragma once
#include "afxdialogex.h"


// CstudentZZDlg 对话框

class CstudentZZDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CstudentZZDlg)

public:
	CstudentZZDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CstudentZZDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG114 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString na1;
	CString na2;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedOk();
};
