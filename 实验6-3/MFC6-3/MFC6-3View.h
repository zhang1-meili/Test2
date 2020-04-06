
// MFC6-3View.h : CMFC63View ��Ľӿ�
//

#pragma once


class CMFC63View : public CView
{
protected: // �������л�����
	CMFC63View();
	DECLARE_DYNCREATE(CMFC63View)

// ����
public:
	CMFC63Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC63View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC6-3View.cpp �еĵ��԰汾
inline CMFC63Doc* CMFC63View::GetDocument() const
   { return reinterpret_cast<CMFC63Doc*>(m_pDocument); }
#endif

