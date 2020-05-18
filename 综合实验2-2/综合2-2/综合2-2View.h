
// 综合2-2View.h : C综合22View 类的接口
//

#pragma once


class C综合22View : public CView
{
protected: // 仅从序列化创建
	C综合22View();
	DECLARE_DYNCREATE(C综合22View)

// 特性
public:
	C综合22Doc* GetDocument() const;

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
	virtual ~C综合22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 综合2-2View.cpp 中的调试版本
inline C综合22Doc* C综合22View::GetDocument() const
   { return reinterpret_cast<C综合22Doc*>(m_pDocument); }
#endif

