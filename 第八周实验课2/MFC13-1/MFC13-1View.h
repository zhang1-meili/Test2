
// MFC13-1View.h : CMFC131View 类的接口
//

#pragma once


class CMFC131View : public CView
{
protected: // 仅从序列化创建
	CMFC131View();
	DECLARE_DYNCREATE(CMFC131View)

// 特性
public:
	CMFC131Doc* GetDocument() const;

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
	virtual ~CMFC131View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void Onpopout();
};

#ifndef _DEBUG  // MFC13-1View.cpp 中的调试版本
inline CMFC131Doc* CMFC131View::GetDocument() const
   { return reinterpret_cast<CMFC131Doc*>(m_pDocument); }
#endif

