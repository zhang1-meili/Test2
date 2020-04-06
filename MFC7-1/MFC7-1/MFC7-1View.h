
// MFC7-1View.h : CMFC71View 类的接口
//

#pragma once


class CMFC71View : public CView
{
protected: // 仅从序列化创建
	CMFC71View();
	DECLARE_DYNCREATE(CMFC71View)

// 特性
public:
	CMFC71Doc* GetDocument() const;

// 操作
public:
	int a;
	CPoint m_pt;
	bool set;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC71View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onshowyuan();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFC7-1View.cpp 中的调试版本
inline CMFC71Doc* CMFC71View::GetDocument() const
   { return reinterpret_cast<CMFC71Doc*>(m_pDocument); }
#endif

