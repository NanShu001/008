#pragma once
#include "afxdialogex.h"


// CTeacherJDDlg 对话框

class CTeacherJDDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTeacherJDDlg)

public:
	CTeacherJDDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTeacherJDDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG14 };
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
