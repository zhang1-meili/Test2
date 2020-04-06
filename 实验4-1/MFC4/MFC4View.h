
// MFC4View.h : CMFC4View ��Ľӿ�
//

#pragma once


class CMFC4View : public CView
{
protected: // �������л�����
	CMFC4View();
	DECLARE_DYNCREATE(CMFC4View)

// ����
public:
	CMFC4Doc* GetDocument() const;

// ����
public:
	CArray<CRect, CRect&>  ca;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC4View.cpp �еĵ��԰汾
inline CMFC4Doc* CMFC4View::GetDocument() const
   { return reinterpret_cast<CMFC4Doc*>(m_pDocument); }
#endif

