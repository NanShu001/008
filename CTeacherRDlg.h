#pragma once
#include "afxdialogex.h"


// CTeacherRDlg 对话框

class CTeacherRDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTeacherRDlg)

public:
	CTeacherRDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTeacherRDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString user;
	CString pas;
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
private:
	CString idd;
};
