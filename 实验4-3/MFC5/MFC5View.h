
// MFC5View.h : CMFC5View ��Ľӿ�
//

#pragma once


class CMFC5View : public CView
{
protected: // �������л�����
	CMFC5View();
	DECLARE_DYNCREATE(CMFC5View)

// ����
public:
	CMFC5Doc* GetDocument() const;

// ����
public:int a, b;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC5View();
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

#ifndef _DEBUG  // MFC5View.cpp �еĵ��԰汾
inline CMFC5Doc* CMFC5View::GetDocument() const
   { return reinterpret_cast<CMFC5Doc*>(m_pDocument); }
#endif

