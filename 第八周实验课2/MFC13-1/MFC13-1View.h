
// MFC13-1View.h : CMFC131View ��Ľӿ�
//

#pragma once


class CMFC131View : public CView
{
protected: // �������л�����
	CMFC131View();
	DECLARE_DYNCREATE(CMFC131View)

// ����
public:
	CMFC131Doc* GetDocument() const;

// ����
public:

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
	virtual ~CMFC131View();
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
	afx_msg void Onpopout();
};

#ifndef _DEBUG  // MFC13-1View.cpp �еĵ��԰汾
inline CMFC131Doc* CMFC131View::GetDocument() const
   { return reinterpret_cast<CMFC131Doc*>(m_pDocument); }
#endif

