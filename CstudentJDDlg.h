#pragma once
#include "afxdialogex.h"


// CstudentJDDlg 对话框

class CstudentJDDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CstudentJDDlg)

public:
	CstudentJDDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CstudentJDDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG113 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString na1;
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
private:
	CString na2;
};
