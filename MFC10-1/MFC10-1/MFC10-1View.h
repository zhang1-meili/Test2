
// MFC10-1View.h : CMFC101View ��Ľӿ�
//

#pragma once


class CMFC101View : public CView
{
protected: // �������л�����
	CMFC101View();
	DECLARE_DYNCREATE(CMFC101View)

// ����
public:
	CMFC101Doc* GetDocument() const;

// ����
public:
	CPoint m_point;
	CString m_strLen;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC101View();
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
	//afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC10-1View.cpp �еĵ��԰汾
inline CMFC101Doc* CMFC101View::GetDocument() const
   { return reinterpret_cast<CMFC101Doc*>(m_pDocument); }
#endif

