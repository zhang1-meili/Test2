
// �ۺ�2-2View.h : C�ۺ�22View ��Ľӿ�
//

#pragma once


class C�ۺ�22View : public CView
{
protected: // �������л�����
	C�ۺ�22View();
	DECLARE_DYNCREATE(C�ۺ�22View)

// ����
public:
	C�ۺ�22Doc* GetDocument() const;

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
	virtual ~C�ۺ�22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // �ۺ�2-2View.cpp �еĵ��԰汾
inline C�ۺ�22Doc* C�ۺ�22View::GetDocument() const
   { return reinterpret_cast<C�ۺ�22Doc*>(m_pDocument); }
#endif

