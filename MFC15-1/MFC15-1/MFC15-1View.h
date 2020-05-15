
// MFC15-1View.h : CMFC151View ��Ľӿ�
//

#pragma once


class CMFC151View : public CView
{
protected: // �������л�����
	CMFC151View();
	DECLARE_DYNCREATE(CMFC151View)

// ����
public:
	CMFC151Doc* GetDocument() const;

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
	virtual ~CMFC151View();
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
};

#ifndef _DEBUG  // MFC15-1View.cpp �еĵ��԰汾
inline CMFC151Doc* CMFC151View::GetDocument() const
   { return reinterpret_cast<CMFC151Doc*>(m_pDocument); }
#endif

