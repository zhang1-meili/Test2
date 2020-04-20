
// MFC14-5View.cpp : CMFC145View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC14-5.h"
#endif

#include "MFC14-5Doc.h"
#include "MFC14-5View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC145View

IMPLEMENT_DYNCREATE(CMFC145View, CView)

BEGIN_MESSAGE_MAP(CMFC145View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popout, &CMFC145View::Onpopout)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC145View ����/����

CMFC145View::CMFC145View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC145View::~CMFC145View()
{
}

BOOL CMFC145View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC145View ����

void CMFC145View::OnDraw(CDC* /*pDC*/)
{
	CMFC145Doc* pDoc = GetDocument();
	CClientDC dc(this);
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect(200, 150, 300, 400);
	dc.Ellipse(&rect);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC145View ��ӡ

BOOL CMFC145View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC145View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC145View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC145View ���

#ifdef _DEBUG
void CMFC145View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC145View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC145Doc* CMFC145View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC145Doc)));
	return (CMFC145Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC145View ��Ϣ�������


void CMFC145View::Onpopout()
{
	CRect cr;
	MyDlg0 dlg;
	CPoint point;
	int t = dlg.DoModal();
	if (t = IDOK) {
		A = dlg.x;
		G= dlg.y;
		B = dlg.z;
}
	// TODO: �ڴ���������������
}


void CMFC145View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CBrush brush(RGB(A, G, B));
	CBrush *oldbrush;
	oldbrush = dc.SelectObject(&brush);
	dc.Ellipse(200, 150, 300, 400);
	dc.SelectObject(oldbrush);
	CView::OnLButtonDown(nFlags, point);
}
