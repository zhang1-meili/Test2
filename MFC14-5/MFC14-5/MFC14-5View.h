
// MFC14-5View.h : CMFC145View ��Ľӿ�
//

#pragma once


class CMFC145View : public CView
{
protected: // �������л�����
	CMFC145View();
	DECLARE_DYNCREATE(CMFC145View)

// ����
public:
	CMFC145Doc* GetDocument() const;

// ����
public:
	int A, G, B;
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
	virtual ~CMFC145View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onpopout();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC14-5View.cpp �еĵ��԰汾
inline CMFC145Doc* CMFC145View::GetDocument() const
   { return reinterpret_cast<CMFC145Doc*>(m_pDocument); }
#endif

