
// 008View.h: CMy008View 类的接口
//

#pragma once


class CMy008View : public CView
{
protected: // 仅从序列化创建
	CMy008View() noexcept;
	DECLARE_DYNCREATE(CMy008View)

// 特性
public:
	CMy008Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy008View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32776();
	afx_msg void On32777();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // 008View.cpp 中的调试版本
inline CMy008Doc* CMy008View::GetDocument() const
   { return reinterpret_cast<CMy008Doc*>(m_pDocument); }
#endif

