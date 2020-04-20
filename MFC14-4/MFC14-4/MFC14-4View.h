
// MFC14-4View.h : CMFC144View 类的接口
//

#pragma once


class CMFC144View : public CView
{
protected: // 仅从序列化创建
	CMFC144View();
	DECLARE_DYNCREATE(CMFC144View)

// 特性
public:
	CMFC144Doc* GetDocument() const;

// 操作
public:
	CRect rect;
	CPoint point1;

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
	virtual ~CMFC144View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC14-4View.cpp 中的调试版本
inline CMFC144Doc* CMFC144View::GetDocument() const
   { return reinterpret_cast<CMFC144Doc*>(m_pDocument); }
#endif

