#pragma once
#include "afxdialogex.h"


// CTeacherTXDlg 对话框

class CTeacherTXDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTeacherTXDlg)

public:
	CTeacherTXDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTeacherTXDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG12 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString na1;
	CString na2;
	CString na3;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
