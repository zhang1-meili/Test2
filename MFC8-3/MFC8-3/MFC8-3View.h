
// MFC8-3View.h : CMFC83View ��Ľӿ�
//

#pragma once


class CMFC83View : public CView
{
protected: // �������л�����
	CMFC83View();
	DECLARE_DYNCREATE(CMFC83View)

// ����
public:
	CMFC83Doc* GetDocument() const;

// ����
public:
	CPoint m_pt;
	UINT m_nd;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC83View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onzhixian();
	afx_msg void Onjuxing();
	afx_msg void Ontuoyuan();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC8-3View.cpp �еĵ��԰汾
inline CMFC83Doc* CMFC83View::GetDocument() const
   { return reinterpret_cast<CMFC83Doc*>(m_pDocument); }
#endif

