
// MFC9-1View.h : CMFC91View ��Ľӿ�
//

#pragma once


class CMFC91View : public CView
{
protected: // �������л�����
	CMFC91View();
	DECLARE_DYNCREATE(CMFC91View)

// ����
public:
	CMFC91Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFC91View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // MFC9-1View.cpp �еĵ��԰汾
inline CMFC91Doc* CMFC91View::GetDocument() const
   { return reinterpret_cast<CMFC91Doc*>(m_pDocument); }
#endif

