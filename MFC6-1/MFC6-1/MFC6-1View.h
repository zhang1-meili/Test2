
// MFC6-1View.h : CMFC61View ��Ľӿ�
//

#pragma once


class CMFC61View : public CView
{
protected: // �������л�����
	CMFC61View();
	DECLARE_DYNCREATE(CMFC61View)

// ����
public:
	CMFC61Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC61View();
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

#ifndef _DEBUG  // MFC6-1View.cpp �еĵ��԰汾
inline CMFC61Doc* CMFC61View::GetDocument() const
   { return reinterpret_cast<CMFC61Doc*>(m_pDocument); }
#endif

