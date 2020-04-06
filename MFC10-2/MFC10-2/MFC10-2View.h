
// MFC10-2View.h : CMFC102View 类的接口
//

#pragma once


class CMFC102View : public CView
{
protected: // 仅从序列化创建
	CMFC102View();
	DECLARE_DYNCREATE(CMFC102View)

// 特性
public:
	CMFC102Doc* GetDocument() const;

// 操作
public:CPoint m_point;
	   CString m_strLen;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC102View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC10-2View.cpp 中的调试版本
inline CMFC102Doc* CMFC102View::GetDocument() const
   { return reinterpret_cast<CMFC102Doc*>(m_pDocument); }
#endif

