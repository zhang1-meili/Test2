
// MFC8-1View.h : CMFC81View ��Ľӿ�
//

#pragma once


class CMFC81View : public CView
{
protected: // �������л�����
	CMFC81View();
	DECLARE_DYNCREATE(CMFC81View)

// ����
public:
	CMFC81Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC81View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // MFC8-1View.cpp �еĵ��԰汾
inline CMFC81Doc* CMFC81View::GetDocument() const
   { return reinterpret_cast<CMFC81Doc*>(m_pDocument); }
#endif

