
// MFC8-2View.h : CMFC82View ��Ľӿ�
//

#pragma once


class CMFC82View : public CView
{
protected: // �������л�����
	CMFC82View();
	DECLARE_DYNCREATE(CMFC82View)

// ����
public:
	CMFC82Doc* GetDocument() const;

// ����
public:
	CBitmap m_Bitmap;
	   int m_nWidth;
	   int m_nHeight;


// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC82View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onshowbitmap();
};

#ifndef _DEBUG  // MFC8-2View.cpp �еĵ��԰汾
inline CMFC82Doc* CMFC82View::GetDocument() const
   { return reinterpret_cast<CMFC82Doc*>(m_pDocument); }
#endif

