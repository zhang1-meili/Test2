
// MFC12-3View.h : CMFC123View ��Ľӿ�
//

#pragma once


class CMFC123View : public CView
{
protected: // �������л�����
	CMFC123View();
	DECLARE_DYNCREATE(CMFC123View)

// ����
public:
	CMFC123Doc* GetDocument() const;

// ����
public:
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
	virtual ~CMFC123View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFC12-3View.cpp �еĵ��԰汾
inline CMFC123Doc* CMFC123View::GetDocument() const
   { return reinterpret_cast<CMFC123Doc*>(m_pDocument); }
#endif

