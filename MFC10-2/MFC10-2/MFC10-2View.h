
// MFC10-2View.h : CMFC102View ��Ľӿ�
//

#pragma once


class CMFC102View : public CView
{
protected: // �������л�����
	CMFC102View();
	DECLARE_DYNCREATE(CMFC102View)

// ����
public:
	CMFC102Doc* GetDocument() const;

// ����
public:CPoint m_point;
	   CString m_strLen;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC102View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC10-2View.cpp �еĵ��԰汾
inline CMFC102Doc* CMFC102View::GetDocument() const
   { return reinterpret_cast<CMFC102Doc*>(m_pDocument); }
#endif

