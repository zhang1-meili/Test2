
// MFC12-4View.h : CMFC124View ��Ľӿ�
//

#pragma once


class CMFC124View : public CView
{
protected: // �������л�����
	CMFC124View();
	DECLARE_DYNCREATE(CMFC124View)

// ����
public:
	CMFC124Doc* GetDocument() const;

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
	virtual ~CMFC124View();
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
	afx_msg void OnBnClickedOk();
};

#ifndef _DEBUG  // MFC12-4View.cpp �еĵ��԰汾
inline CMFC124Doc* CMFC124View::GetDocument() const
   { return reinterpret_cast<CMFC124Doc*>(m_pDocument); }
#endif

