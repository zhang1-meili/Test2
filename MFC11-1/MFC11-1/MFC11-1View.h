
// MFC11-1View.h : CMFC111View 类的接口
//

#pragma once


class CMFC111View : public CView
{
protected: // 仅从序列化创建
	CMFC111View();
	DECLARE_DYNCREATE(CMFC111View)

// 特性
public:
	CMFC111Doc* GetDocument() const;

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
	virtual ~CMFC111View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onputout();
};

#ifndef _DEBUG  // MFC11-1View.cpp 中的调试版本
inline CMFC111Doc* CMFC111View::GetDocument() const
   { return reinterpret_cast<CMFC111Doc*>(m_pDocument); }
#endif

