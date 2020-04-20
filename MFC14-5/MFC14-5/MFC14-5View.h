
// MFC14-5View.h : CMFC145View 类的接口
//

#pragma once


class CMFC145View : public CView
{
protected: // 仅从序列化创建
	CMFC145View();
	DECLARE_DYNCREATE(CMFC145View)

// 特性
public:
	CMFC145Doc* GetDocument() const;

// 操作
public:
	int A, G, B;
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
	virtual ~CMFC145View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onpopout();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC14-5View.cpp 中的调试版本
inline CMFC145Doc* CMFC145View::GetDocument() const
   { return reinterpret_cast<CMFC145Doc*>(m_pDocument); }
#endif

