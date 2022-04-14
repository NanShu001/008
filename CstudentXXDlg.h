#pragma once
#include "afxdialogex.h"


// CstudentXXDlg 对话框

class CstudentXXDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CstudentXXDlg)

public:
	CstudentXXDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CstudentXXDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG111 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString na1;
	CString na2;
	CString na3;
	CString na4;
	CString na5;
	CString na6;
	CString na7;
public:
	afx_msg void OnBnClickedOk2();
};
