
// MFC12-3View.cpp : CMFC123View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC12-3.h"
#endif

#include "MFC12-3Doc.h"
#include "MFC12-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC123View

IMPLEMENT_DYNCREATE(CMFC123View, CView)

BEGIN_MESSAGE_MAP(CMFC123View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC123View ����/����

CMFC123View::CMFC123View()
{
	set = false;
	// TODO: �ڴ˴���ӹ������

}

CMFC123View::~CMFC123View()
{
}

BOOL CMFC123View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC123View ����

void CMFC123View::OnDraw(CDC* pDC)
{
	CMFC123Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
  
	if (!pDoc)
		return;
	pDC->Ellipse(pDoc->rect);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC123View ��ӡ

BOOL CMFC123View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC123View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC123View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC123View ���

#ifdef _DEBUG
void CMFC123View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC123View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC123Doc* CMFC123View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC123Doc)));
	return (CMFC123Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC123View ��Ϣ�������


void CMFC123View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	KillTimer(2);
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFC123View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMFC123Doc* pDoc = GetDocument();
	CClientDC dc(this);
	SetTimer(2, 1000, NULL);
	set = true;
	if (set == true) {
		dc.Ellipse(pDoc->rect);
	}
	
	CView::OnLButtonDown(nFlags, point);
}


void CMFC123View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC123Doc* pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (pDoc->rect.right>clientRec.right ) {
		pDoc->rect.left -= 20;
		pDoc->rect.right -= 20;
		Invalidate();

	}
	else{
		pDoc->rect.left+= 20;
		pDoc->rect.right += 20;
		Invalidate();
	}
	CView::OnTimer(nIDEvent);
}
