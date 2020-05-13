
// MFC15-2View.h : CMFC152View 类的接口
//

#pragma once


class CMFC152View : public CView
{
protected: // 仅从序列化创建
	CMFC152View();
	DECLARE_DYNCREATE(CMFC152View)

// 特性
public:
	CMFC152Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC152View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnBnClickedButton1();
	afx_msg void Onpopout();
};

#ifndef _DEBUG  // MFC15-2View.cpp 中的调试版本
inline CMFC152Doc* CMFC152View::GetDocument() const
   { return reinterpret_cast<CMFC152Doc*>(m_pDocument); }
#endif

