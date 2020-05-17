
// MFCA13-3View.h : CMFCA133View 类的接口
//

#pragma once


class CMFCA133View : public CView
{
protected: // 仅从序列化创建
	CMFCA133View();
	DECLARE_DYNCREATE(CMFCA133View)

// 特性
public:
	CMFCA133Doc* GetDocument() const;

// 操作
public:
	

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCA133View();
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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCA13-3View.cpp 中的调试版本
inline CMFCA133Doc* CMFCA133View::GetDocument() const
   { return reinterpret_cast<CMFCA133Doc*>(m_pDocument); }
#endif

