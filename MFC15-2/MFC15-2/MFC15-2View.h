
// MFC15-2View.h : CMFC152View ��Ľӿ�
//

#pragma once


class CMFC152View : public CView
{
protected: // �������л�����
	CMFC152View();
	DECLARE_DYNCREATE(CMFC152View)

// ����
public:
	CMFC152Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC152View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnBnClickedButton1();
	afx_msg void Onpopout();
};

#ifndef _DEBUG  // MFC15-2View.cpp �еĵ��԰汾
inline CMFC152Doc* CMFC152View::GetDocument() const
   { return reinterpret_cast<CMFC152Doc*>(m_pDocument); }
#endif

