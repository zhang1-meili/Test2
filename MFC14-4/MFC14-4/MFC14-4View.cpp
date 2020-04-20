
// MFC14-4View.cpp : CMFC144View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC14-4.h"
#endif

#include "MFC14-4Doc.h"
#include "MFC14-4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC144View

IMPLEMENT_DYNCREATE(CMFC144View, CView)

BEGIN_MESSAGE_MAP(CMFC144View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC144View ����/����

CMFC144View::CMFC144View()
{
	// TODO: �ڴ˴���ӹ������
	point1.x = 200;
	point1.y = 300;

}

CMFC144View::~CMFC144View()
{
}

BOOL CMFC144View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC144View ����

void CMFC144View::OnDraw(CDC* /*pDC*/)
{
	CMFC144Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	rect.left = point1.x - 50;
	rect.top = point1.y - 60;
	rect.right = point1.x + 70;
	rect.bottom = point1.y + 80;
	dc.Ellipse(&rect);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC144View ��ӡ

BOOL CMFC144View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC144View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC144View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC144View ���

#ifdef _DEBUG
void CMFC144View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC144View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC144Doc* CMFC144View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC144Doc)));
	return (CMFC144Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC144View ��Ϣ�������


void CMFC144View::OnLButtonDown(UINT nFlags, CPoint point)
{
	//int red = 0, green = 0, blue = 0;
	int width = 1;
	int color = RGB(255, 0, 0);
	CClientDC dc(this);
	CRect rect1;
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (point.x >150 && point.x <270 && point.y>240&& point.y <380)
	{
		CPen newPen(PS_DASH, width, color);
		CPen *oldPen = dc.SelectObject(&newPen);
		rect1.left = point1.x - 50;
		rect1.top = point1.y - 60;
		rect1.right = point1.x + 70;
		rect1.bottom = point1.y + 80;
		dc.Rectangle(&rect1);
		dc.SelectObject(oldPen);
	}
	dc.Ellipse(&rect);
	CView::OnLButtonDown(nFlags, point);
}
