
// usingLibDllView.cpp : CusingLibDllView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "usingLibDll.h"
#endif

#include "usingLibDllDoc.h"
#include "usingLibDllView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "w32.h"
#include "W32D.h"

// CusingLibDllView

IMPLEMENT_DYNCREATE(CusingLibDllView, CView)

BEGIN_MESSAGE_MAP(CusingLibDllView, CView)
END_MESSAGE_MAP()

// CusingLibDllView ����/����

CusingLibDllView::CusingLibDllView()
{
	// TODO: �ڴ˴���ӹ������

}

CusingLibDllView::~CusingLibDllView()
{
}

BOOL CusingLibDllView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CusingLibDllView ����

void CusingLibDllView::OnDraw(CDC* pDC)
{
	CusingLibDllDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	int a;
	a=factorial(5);
	s.Format(_T("%d,���Ǿ�̬������5�Ľ׳�"), a);
	pDC->TextOutW(200, 150,s);//��̬����
	CString ss;
	ss.Format(_T("%d�����Ƕ�̬������5�Ľ׳�"), factorial1(5));
	pDC->TextOutW(200, 250, ss);//��̬����
	FAC fac;
	CString s1;
    s1.Format(_T("%f�����Ǿ�̬���ӰѽǶ�ת��Ϊ����"), fac.convert(30.0));
	pDC->TextOutW(200, 350, s1);//��̬����
	CString s2;
	s2.Format(_T("%f�����Ƕ�̬���ӰѽǶ�ת��Ϊ����"),convert1(30.0));
	pDC->TextOutW(200, 450, s2);//��̬����
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CusingLibDllView ���

#ifdef _DEBUG
void CusingLibDllView::AssertValid() const
{
	CView::AssertValid();
}

void CusingLibDllView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CusingLibDllDoc* CusingLibDllView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CusingLibDllDoc)));
	return (CusingLibDllDoc*)m_pDocument;
}
#endif //_DEBUG


// CusingLibDllView ��Ϣ�������
