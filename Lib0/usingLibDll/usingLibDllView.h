
// usingLibDllView.h : CusingLibDllView ��Ľӿ�
//

#pragma once


class CusingLibDllView : public CView
{
protected: // �������л�����
	CusingLibDllView();
	DECLARE_DYNCREATE(CusingLibDllView)

// ����
public:
	CusingLibDllDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CusingLibDllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // usingLibDllView.cpp �еĵ��԰汾
inline CusingLibDllDoc* CusingLibDllView::GetDocument() const
   { return reinterpret_cast<CusingLibDllDoc*>(m_pDocument); }
#endif

