
// MFC14-1View.h : CMFC141View ��Ľӿ�
//

#pragma once


class CMFC141View : public CView
{
protected: // �������л�����
	CMFC141View();
	DECLARE_DYNCREATE(CMFC141View)

// ����
public:
	CMFC141Doc* GetDocument() const;

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
	virtual ~CMFC141View();
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

#ifndef _DEBUG  // MFC14-1View.cpp �еĵ��԰汾
inline CMFC141Doc* CMFC141View::GetDocument() const
   { return reinterpret_cast<CMFC141Doc*>(m_pDocument); }
#endif

