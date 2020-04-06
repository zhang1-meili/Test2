
// MFC5View.cpp : CMFC5View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC5.h"
#endif

#include "MFC5Doc.h"
#include "MFC5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC5View

IMPLEMENT_DYNCREATE(CMFC5View, CView)

BEGIN_MESSAGE_MAP(CMFC5View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC5View ����/����

CMFC5View::CMFC5View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC5View::~CMFC5View()
{
}

BOOL CMFC5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC5View ����

void CMFC5View::OnDraw(CDC* pDC)
{
	CMFC5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->rect);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC5View ���

#ifdef _DEBUG
void CMFC5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC5Doc* CMFC5View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC5Doc)));
	return (CMFC5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC5View ��Ϣ�������


void CMFC5View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString s;
	s.Format(_T("λ�ã�x=%d,y=%d"), point.x, point.y);
	dc.TextOutW(200, 200, s);
	CView::OnMouseMove(nFlags, point);
}


void CMFC5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC5Doc* pDoc = GetDocument();
	pDoc->rect.left = point.x;
	pDoc->rect.top = point.y;

	CView::OnLButtonDown(nFlags, point);
}


void CMFC5View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC5Doc* pDoc = GetDocument();
	pDoc->rect.right = point.x;
	pDoc->rect.bottom = point.y;
	InvalidateRect(NULL, FALSE);

	CView::OnLButtonUp(nFlags, point);
}
