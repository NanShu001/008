#pragma once
#include "afxdialogex.h"


// CLogin2Dlg 对话框

class CLogin2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLogin2Dlg)

public:
	CLogin2Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CLogin2Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
private:
	CString user0;
	CString pas0;
};
