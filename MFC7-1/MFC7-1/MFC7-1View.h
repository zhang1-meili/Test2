
// MFC7-1View.h : CMFC71View ��Ľӿ�
//

#pragma once


class CMFC71View : public CView
{
protected: // �������л�����
	CMFC71View();
	DECLARE_DYNCREATE(CMFC71View)

// ����
public:
	CMFC71Doc* GetDocument() const;

// ����
public:
	int a;
	CPoint m_pt;
	bool set;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC71View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onshowyuan();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFC7-1View.cpp �еĵ��԰汾
inline CMFC71Doc* CMFC71View::GetDocument() const
   { return reinterpret_cast<CMFC71Doc*>(m_pDocument); }
#endif

