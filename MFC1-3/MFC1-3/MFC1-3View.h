
// MFC1-3View.h : CMFC13View ��Ľӿ�
//

#pragma once


class CMFC13View : public CView
{
protected: // �������л�����
	CMFC13View();
	DECLARE_DYNCREATE(CMFC13View)

// ����
public:
	CMFC13Doc* GetDocument() const;

// ����
public:
	CString ss;

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
	virtual ~CMFC13View();
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

#ifndef _DEBUG  // MFC1-3View.cpp �еĵ��԰汾
inline CMFC13Doc* CMFC13View::GetDocument() const
   { return reinterpret_cast<CMFC13Doc*>(m_pDocument); }
#endif

