
// MFC1-3View.h : CMFC13View 类的接口
//

#pragma once


class CMFC13View : public CView
{
protected: // 仅从序列化创建
	CMFC13View();
	DECLARE_DYNCREATE(CMFC13View)

// 特性
public:
	CMFC13Doc* GetDocument() const;

// 操作
public:
	CString ss;

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
	virtual ~CMFC13View();
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

#ifndef _DEBUG  // MFC1-3View.cpp 中的调试版本
inline CMFC13Doc* CMFC13View::GetDocument() const
   { return reinterpret_cast<CMFC13Doc*>(m_pDocument); }
#endif

