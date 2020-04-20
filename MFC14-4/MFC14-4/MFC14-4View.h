
// MFC14-4View.h : CMFC144View ��Ľӿ�
//

#pragma once


class CMFC144View : public CView
{
protected: // �������л�����
	CMFC144View();
	DECLARE_DYNCREATE(CMFC144View)

// ����
public:
	CMFC144Doc* GetDocument() const;

// ����
public:
	CRect rect;
	CPoint point1;

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
	virtual ~CMFC144View();
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
};

#ifndef _DEBUG  // MFC14-4View.cpp �еĵ��԰汾
inline CMFC144Doc* CMFC144View::GetDocument() const
   { return reinterpret_cast<CMFC144Doc*>(m_pDocument); }
#endif

