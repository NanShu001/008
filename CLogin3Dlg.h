#pragma once
#include "afxdialogex.h"


// CLogin3Dlg 对话框

class CLogin3Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLogin3Dlg)

public:
	CLogin3Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CLogin3Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
private:
	CString user2;
	CString pas2;
};
