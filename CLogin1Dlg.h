#pragma once
#include "afxdialogex.h"


// CLogin1Dlg 对话框

class CLogin1Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLogin1Dlg)

public:
	CLogin1Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CLogin1Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
private:
	CString user0;
	CString pas0;
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEdit1();
};
