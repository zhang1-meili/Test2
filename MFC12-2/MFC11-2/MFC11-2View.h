
// MFC11-2View.h : CMFC112View ��Ľӿ�
//

#pragma once


class CMFC112View : public CView
{
protected: // �������л�����
	CMFC112View();
	DECLARE_DYNCREATE(CMFC112View)

// ����
public:
	CMFC112Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC112View();
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

#ifndef _DEBUG  // MFC11-2View.cpp �еĵ��԰汾
inline CMFC112Doc* CMFC112View::GetDocument() const
   { return reinterpret_cast<CMFC112Doc*>(m_pDocument); }
#endif

