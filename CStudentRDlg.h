#pragma once
#include "afxdialogex.h"


// CStudentRDlg 对话框

class CStudentRDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStudentRDlg)

public:
	CStudentRDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CStudentRDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString user;
	CString pas;
public:
	afx_msg void OnBnClickedOk();
private:
	CString idd;
};
