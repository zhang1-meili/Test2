
// MFCA13-3View.h : CMFCA133View ��Ľӿ�
//

#pragma once


class CMFCA133View : public CView
{
protected: // �������л�����
	CMFCA133View();
	DECLARE_DYNCREATE(CMFCA133View)

// ����
public:
	CMFCA133Doc* GetDocument() const;

// ����
public:
	

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCA133View();
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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCA13-3View.cpp �еĵ��԰汾
inline CMFCA133Doc* CMFCA133View::GetDocument() const
   { return reinterpret_cast<CMFCA133Doc*>(m_pDocument); }
#endif

