
// MFC13-2View.h : CMFC132View ��Ľӿ�
//

#pragma once


class CMFC132View : public CView
{
protected: // �������л�����
	CMFC132View();
	DECLARE_DYNCREATE(CMFC132View)

// ����
public:
	CMFC132Doc* GetDocument() const;

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
	virtual ~CMFC132View();
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

#ifndef _DEBUG  // MFC13-2View.cpp �еĵ��԰汾
inline CMFC132Doc* CMFC132View::GetDocument() const
   { return reinterpret_cast<CMFC132Doc*>(m_pDocument); }
#endif

