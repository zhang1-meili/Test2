
// ������ʵ���3View.h : C������ʵ���3View ��Ľӿ�
//

#pragma once


class C������ʵ���3View : public CView
{
protected: // �������л�����
	C������ʵ���3View();
	DECLARE_DYNCREATE(C������ʵ���3View)

// ����
public:
	C������ʵ���3Doc* GetDocument() const;

// ����
public:
	CString ss[36];
	int i;

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
	virtual ~C������ʵ���3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // ������ʵ���3View.cpp �еĵ��԰汾
inline C������ʵ���3Doc* C������ʵ���3View::GetDocument() const
   { return reinterpret_cast<C������ʵ���3Doc*>(m_pDocument); }
#endif

