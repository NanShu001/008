#pragma once
#include "afxdialogex.h"


// CyemianDlg 对话框

class CyemianDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CyemianDlg)

public:
	CyemianDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CyemianDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG9 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString na1;
	afx_msg void OnEnChangeEdit1();
private:
	CString na2;
public:
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton1();
};
