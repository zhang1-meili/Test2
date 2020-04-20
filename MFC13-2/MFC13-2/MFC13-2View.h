
// MFC13-2View.h : CMFC132View 类的接口
//

#pragma once


class CMFC132View : public CView
{
protected: // 仅从序列化创建
	CMFC132View();
	DECLARE_DYNCREATE(CMFC132View)

// 特性
public:
	CMFC132Doc* GetDocument() const;

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
	virtual ~CMFC132View();
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

#ifndef _DEBUG  // MFC13-2View.cpp 中的调试版本
inline CMFC132Doc* CMFC132View::GetDocument() const
   { return reinterpret_cast<CMFC132Doc*>(m_pDocument); }
#endif

