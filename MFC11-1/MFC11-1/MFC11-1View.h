
// MFC11-1View.h : CMFC111View ��Ľӿ�
//

#pragma once


class CMFC111View : public CView
{
protected: // �������л�����
	CMFC111View();
	DECLARE_DYNCREATE(CMFC111View)

// ����
public:
	CMFC111Doc* GetDocument() const;

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
	virtual ~CMFC111View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onputout();
};

#ifndef _DEBUG  // MFC11-1View.cpp �еĵ��԰汾
inline CMFC111Doc* CMFC111View::GetDocument() const
   { return reinterpret_cast<CMFC111Doc*>(m_pDocument); }
#endif

