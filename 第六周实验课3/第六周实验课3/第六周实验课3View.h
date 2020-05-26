
// 第六周实验课3View.h : C第六周实验课3View 类的接口
//

#pragma once


class C第六周实验课3View : public CView
{
protected: // 仅从序列化创建
	C第六周实验课3View();
	DECLARE_DYNCREATE(C第六周实验课3View)

// 特性
public:
	C第六周实验课3Doc* GetDocument() const;

// 操作
public:
	CString ss[36];
	int i;

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
	virtual ~C第六周实验课3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // 第六周实验课3View.cpp 中的调试版本
inline C第六周实验课3Doc* C第六周实验课3View::GetDocument() const
   { return reinterpret_cast<C第六周实验课3Doc*>(m_pDocument); }
#endif

