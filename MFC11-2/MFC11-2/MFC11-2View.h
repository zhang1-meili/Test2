
// MFC11-2View.h : CMFC112View 类的接口
//

#pragma once


class CMFC112View : public CView
{
protected: // 仅从序列化创建
	CMFC112View();
	DECLARE_DYNCREATE(CMFC112View)

// 特性
public:
	CMFC112Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC112View();
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

#ifndef _DEBUG  // MFC11-2View.cpp 中的调试版本
inline CMFC112Doc* CMFC112View::GetDocument() const
   { return reinterpret_cast<CMFC112Doc*>(m_pDocument); }
#endif

