
// MFC6-2View.h : CMFC62View ��Ľӿ�
//

#pragma once


class CMFC62View : public CView
{
protected: // �������л�����
	CMFC62View();
	DECLARE_DYNCREATE(CMFC62View)

// ����
public:
	CMFC62Doc* GetDocument() const;

// ����
public:int N;
 CArray <CRect, CRect> cr;
 bool set;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC62View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFC6-2View.cpp �еĵ��԰汾
inline CMFC62Doc* CMFC62View::GetDocument() const
   { return reinterpret_cast<CMFC62Doc*>(m_pDocument); }
#endif

