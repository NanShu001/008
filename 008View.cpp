
// 008View.cpp: CMy008View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "008.h"
#endif

#include "008Doc.h"
#include "008View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CLogin1Dlg.h"
#include "CLogin2Dlg.h"
#include "CLogin3Dlg.h"
#include "CStudentRDlg.h"
#include "CTeacherRDlg.h"
// CMy008View

IMPLEMENT_DYNCREATE(CMy008View, CView)

BEGIN_MESSAGE_MAP(CMy008View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CMy008View::On32771)
	ON_COMMAND(ID_32772, &CMy008View::On32772)
	ON_COMMAND(ID_32773, &CMy008View::On32773)
	ON_COMMAND(ID_32776, &CMy008View::On32776)
	ON_COMMAND(ID_32777, &CMy008View::On32777)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMy008View 构造/析构

CMy008View::CMy008View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy008View::~CMy008View()
{
}

BOOL CMy008View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy008View 绘图

void CMy008View::OnDraw(CDC* pDC)
{
	CMy008Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString str;
	str = "家教管理系统                                                       (系统暂不支持中文，请输入英文或代码）";
	pDC->TextOut(100, 100, str);



	// TODO: 在此处为本机数据添加绘制代码
}


// CMy008View 打印

BOOL CMy008View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy008View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy008View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy008View 诊断

#ifdef _DEBUG
void CMy008View::AssertValid() const
{
	CView::AssertValid();
}

void CMy008View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy008Doc* CMy008View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy008Doc)));
	return (CMy008Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy008View 消息处理程序


void CMy008View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	CLogin1Dlg dia;
	dia.DoModal();
}


void CMy008View::On32772()
{
	// TODO: 在此添加命令处理程序代码
	CLogin2Dlg dia;
	dia.DoModal();
}


void CMy008View::On32773()
{
	// TODO: 在此添加命令处理程序代码
	CLogin3Dlg dia;
	dia.DoModal();
}


void CMy008View::On32776()
{
	// TODO: 在此添加命令处理程序代码
	CStudentRDlg dlg;
	dlg.DoModal();
}


void CMy008View::On32777()
{
	// TODO: 在此添加命令处理程序代码
	CTeacherRDlg dlg;
	dlg.DoModal();
}

CButton restart;
int CMy008View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO:  在此添加您专用的创建代码

}
