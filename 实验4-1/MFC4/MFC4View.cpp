
// MFC4View.cpp : CMFC4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC4.h"
#endif

#include "MFC4Doc.h"
#include "MFC4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4View

IMPLEMENT_DYNCREATE(CMFC4View, CView)

BEGIN_MESSAGE_MAP(CMFC4View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC4View ����/����

CMFC4View::CMFC4View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC4View::~CMFC4View()
{
}

BOOL CMFC4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC4View ����

void CMFC4View::OnDraw(CDC* pDC)
{
	CMFC4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}


// CMFC4View ���

#ifdef _DEBUG
void CMFC4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4Doc* CMFC4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4Doc)));
	return (CMFC4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4View ��Ϣ�������


void CMFC4View::OnLButtonDown(UINT nFlags, CPoint point)
{ 
	CClientDC dc(this);
	CString S;
	S.Format(_T("�����������"));
	dc.TextOutW(200, 500, S);


	CView::OnLButtonDown(nFlags, point);
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
}


void CMFC4View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CClientDC dc(this);
	CString S;
	S.Format(_T("������ڵ���"));
	dc.TextOutW(500, 500, S);

	CView::OnLButtonUp(nFlags, point);
}
