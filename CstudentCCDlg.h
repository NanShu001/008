#pragma once
#include "afxdialogex.h"


// CstudentCCDlg 对话框

class CstudentCCDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CstudentCCDlg)

public:
	CstudentCCDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CstudentCCDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG112 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString na2;
	CString na3;
	CString na1;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
