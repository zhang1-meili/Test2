
// MFC12-1View.h : CMFC121View ��Ľӿ�
//

#pragma once


class CMFC121View : public CView
{
protected: // �������л�����
	CMFC121View();
	DECLARE_DYNCREATE(CMFC121View)

// ����
public:
	CMFC121Doc* GetDocument() const;

// ����
public:
	CRect rect;
	bool set;
	CPoint point1;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC121View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC12-1View.cpp �еĵ��԰汾
inline CMFC121Doc* CMFC121View::GetDocument() const
   { return reinterpret_cast<CMFC121Doc*>(m_pDocument); }
#endif

