
// MFC12-1View.cpp : CMFC121View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC12-1.h"
#endif

#include "MFC12-1Doc.h"
#include "MFC12-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC121View

IMPLEMENT_DYNCREATE(CMFC121View, CView)

BEGIN_MESSAGE_MAP(CMFC121View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC121View ����/����

CMFC121View::CMFC121View()
{
	// TODO: �ڴ˴���ӹ������
	set = false;
	point1.x = 200;
	point1.y = 300;

}

CMFC121View::~CMFC121View()
{
}

BOOL CMFC121View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC121View ����

void CMFC121View::OnDraw(CDC* /*pDC*/)
{
	CMFC121Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	rect.left = point1.x - 50;
	rect.top = point1.y - 60;
	rect.right = point1.x + 70;
	rect.bottom = point1.y + 80;
	dc.Rectangle(&rect);
	// TODO: �ڴ˴�Ϊ.y.
}

// CMFC121View ���

#ifdef _DEBUG
void CMFC121View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC121View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC121Doc* CMFC121View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC121Doc)));
	return (CMFC121Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC121View ��Ϣ�������


void CMFC121View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = true;

	CView::OnLButtonDown(nFlags, point);
}


void CMFC121View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = false;
	CView::OnLButtonUp(nFlags, point);
}


void CMFC121View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (set) {
		point1 = point;
		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}
