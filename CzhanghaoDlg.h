#pragma once
#include "afxdialogex.h"


// CzhanghaoDlg 对话框

class CzhanghaoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CzhanghaoDlg)

public:
	CzhanghaoDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CzhanghaoDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG92 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString na1;
	CString na2;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
