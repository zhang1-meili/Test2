
// MFC15-1View.h : CMFC151View 类的接口
//

#pragma once


class CMFC151View : public CView
{
protected: // 仅从序列化创建
	CMFC151View();
	DECLARE_DYNCREATE(CMFC151View)

// 特性
public:
	CMFC151Doc* GetDocument() const;

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
	virtual ~CMFC151View();
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
};

#ifndef _DEBUG  // MFC15-1View.cpp 中的调试版本
inline CMFC151Doc* CMFC151View::GetDocument() const
   { return reinterpret_cast<CMFC151Doc*>(m_pDocument); }
#endif

