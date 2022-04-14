#pragma once
#include "afxdialogex.h"


// CTeacherXXDlg 对话框

class CTeacherXXDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTeacherXXDlg)

public:
	CTeacherXXDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTeacherXXDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG10 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
private:
	CString na1;
	CString na2;
	CString na3;
	CString na4;
	CString na5;
	CString na6;
	CString na7;
};
