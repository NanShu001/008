#pragma once
#include "afxdialogex.h"


// CzhifuDlg 对话框

class CzhifuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CzhifuDlg)

public:
	CzhifuDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CzhifuDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG91 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString na1;
	CString na2;
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
private:
	CString na3;
public:
	afx_msg void OnBnClickedButton3();
};
