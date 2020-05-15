
// ������ʵ���-1View.cpp : C������ʵ���1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ���-1.h"
#endif

#include "������ʵ���-1Doc.h"
#include "������ʵ���-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ���1View

IMPLEMENT_DYNCREATE(C������ʵ���1View, CView)

BEGIN_MESSAGE_MAP(C������ʵ���1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C������ʵ���1View ����/����

C������ʵ���1View::C������ʵ���1View()
{
	// TODO: �ڴ˴���ӹ������

}

C������ʵ���1View::~C������ʵ���1View()
{
}

BOOL C������ʵ���1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ���1View ����

void C������ʵ���1View::OnDraw(CDC* /*pDC*/)
{
	C������ʵ���1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C������ʵ���1View ��ӡ

BOOL C������ʵ���1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C������ʵ���1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C������ʵ���1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C������ʵ���1View ���

#ifdef _DEBUG
void C������ʵ���1View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ���1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ���1Doc* C������ʵ���1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ���1Doc)));
	return (C������ʵ���1Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ���1View ��Ϣ�������


void C������ʵ���1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C������ʵ���1Doc* pDoc = GetDocument();
	pDoc->x1.x = point.x;
	CView::OnLButtonDown(nFlags, point);
}


void C������ʵ���1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C������ʵ���1Doc* pDoc = GetDocument();
	pDoc->x2.x = point.x;
	CClientDC dc(this);
	CString s1, s2;
	s1.Format(_T("%d"), pDoc->count);
	int x3;
	x3 = (pDoc->x2.x - pDoc->x1.x) / pDoc->count;
	s2.Format(_T("%d"), x3);
	dc.TextOutW(20, 20, s1);
	dc.TextOutW(20, 40, s2);
	pDoc->count = 0;
	CView::OnLButtonUp(nFlags, point);

}


void C������ʵ���1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C������ʵ���1Doc* pDoc = GetDocument();
	pDoc->count= pDoc->count+1;
	CView::OnMouseMove(nFlags, point);
}
