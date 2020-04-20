
// MFC14-2View.h : CMFC142View ��Ľӿ�
//

#pragma once


class CMFC142View : public CView
{
protected: // �������л�����
	CMFC142View();
	DECLARE_DYNCREATE(CMFC142View)

// ����
public:
	CMFC142Doc* GetDocument() const;

// ����
public:
	CRect rect;
	int r;
	int R;

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
	virtual ~CMFC142View();
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

#ifndef _DEBUG  // MFC14-2View.cpp �еĵ��԰汾
inline CMFC142Doc* CMFC142View::GetDocument() const
   { return reinterpret_cast<CMFC142Doc*>(m_pDocument); }
#endif

