
// MFC14-3View.h : CMFC143View ��Ľӿ�
//

#pragma once


class CMFC143View : public CView
{
protected: // �������л�����
	CMFC143View();
	DECLARE_DYNCREATE(CMFC143View)
// ����
public:
	CMFC143Doc* GetDocument() const;

// ����
public:
	CRect rect;
	CPoint point1;
	bool set;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFC143View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC14-3View.cpp �еĵ��԰汾
inline CMFC143Doc* CMFC143View::GetDocument() const
   { return reinterpret_cast<CMFC143Doc*>(m_pDocument); }
#endif

