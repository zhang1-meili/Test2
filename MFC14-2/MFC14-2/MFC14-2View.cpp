
// MFC14-2View.cpp : CMFC142View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC14-2.h"
#endif

#include "MFC14-2Doc.h"
#include "MFC14-2View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC142View

IMPLEMENT_DYNCREATE(CMFC142View, CView)

BEGIN_MESSAGE_MAP(CMFC142View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popout, &CMFC142View::Onpopout)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC142View ����/����

CMFC142View::CMFC142View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC142View::~CMFC142View()
{
}

BOOL CMFC142View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC142View ����

void CMFC142View::OnDraw(CDC* pDC)
{
	
	CPoint point;
	CMFC142Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(rect);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC142View ��ӡ

BOOL CMFC142View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC142View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC142View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC142View ���

#ifdef _DEBUG
void CMFC142View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC142View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC142Doc* CMFC142View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC142Doc)));
	return (CMFC142Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC142View ��Ϣ�������




void CMFC142View::Onpopout()
{
	CRect cr;
	MyDlg0 dlg;
	CPoint point;
	int t = dlg.DoModal();
	if (t = IDOK) {
		r= dlg.r1;
		R = dlg.r2;
	}

	// TODO: �ڴ���������������
}


void CMFC142View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	rect.left = point.x - r;
	rect.right = point.x + r;
	rect.top = point.y - R;
	rect.bottom = point.y + R;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
