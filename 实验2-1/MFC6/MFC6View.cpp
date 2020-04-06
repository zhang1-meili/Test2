
// MFC6View.cpp : CMFC6View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC6.h"
#endif

#include "MFC6Doc.h"
#include "MFC6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC6View

IMPLEMENT_DYNCREATE(CMFC6View, CView)

BEGIN_MESSAGE_MAP(CMFC6View, CView)
END_MESSAGE_MAP()

// CMFC6View ����/����

CMFC6View::CMFC6View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC6View::~CMFC6View()
{
}

BOOL CMFC6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC6View ����

void CMFC6View::OnDraw(CDC* pDC)
{
	CMFC6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString S;
	S.Format(_T("������˼��"));
	pDC->TextOutW(100, 200, S);
	int A = 20;
	CString s;
	s.Format(_T("%d"), A);
	pDC->TextOutW(100, 300, s);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC6View ���

#ifdef _DEBUG
void CMFC6View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC6Doc* CMFC6View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC6Doc)));
	return (CMFC6Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC6View ��Ϣ�������
