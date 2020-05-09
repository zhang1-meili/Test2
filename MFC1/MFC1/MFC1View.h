
// MFC1View.h : CMFC1View ��Ľӿ�
//

#pragma once


class CMFC1View : public CView
{
protected: // �������л�����
	CMFC1View();
	DECLARE_DYNCREATE(CMFC1View)

// ����
public:
	CMFC1Doc* GetDocument() const;

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
	virtual ~CMFC1View();
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

#ifndef _DEBUG  // MFC1View.cpp �еĵ��԰汾
inline CMFC1Doc* CMFC1View::GetDocument() const
   { return reinterpret_cast<CMFC1Doc*>(m_pDocument); }
#endif

