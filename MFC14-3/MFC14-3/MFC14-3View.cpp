
// MFC14-3View.cpp : CMFC143View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC14-3.h"
#endif

#include "MFC14-3Doc.h"
#include "MFC14-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC143View

IMPLEMENT_DYNCREATE(CMFC143View, CView)

BEGIN_MESSAGE_MAP(CMFC143View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC143View ����/����

CMFC143View::CMFC143View()
{
	// TODO: 
	set = false;
	point1.x = 200;
	point1.y = 300;

}

CMFC143View::~CMFC143View()
{
}

BOOL CMFC143View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC143View ����

void CMFC143View::OnDraw(CDC* pDC)
{
	CMFC143Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	rect.left = point1.x - 50;
	rect.top = point1.y - 60;
	rect.right = point1.x +70;
	rect.bottom = point1.y + 80;
	dc.Ellipse(&rect);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC143View ��ӡ

BOOL CMFC143View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC143View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC143View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC143View ���

#ifdef _DEBUG
void CMFC143View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC143View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC143Doc* CMFC143View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC143Doc)));
	return (CMFC143Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC143View ��Ϣ�������


void CMFC143View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC143Doc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);
	if(set){
	point1 = point;
	Invalidate();
}
	CView::OnMouseMove(nFlags, point);
}


void CMFC143View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = true;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC143View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = false;
	CView::OnLButtonUp(nFlags, point);
}
