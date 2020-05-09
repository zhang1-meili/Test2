
// MFC1-3View.cpp : CMFC13View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC1-3.h"
#endif

#include "MFC1-3Doc.h"
#include "MFC1-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC13View

IMPLEMENT_DYNCREATE(CMFC13View, CView)

BEGIN_MESSAGE_MAP(CMFC13View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC13View ����/����

CMFC13View::CMFC13View()
{
	// TODO: �ڴ˴���ӹ������
	ss = "�����ֻ�";
}

CMFC13View::~CMFC13View()
{
}

BOOL CMFC13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC13View ����

void CMFC13View::OnDraw(CDC* /*pDC*/)
{
	CMFC13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC13View ��ӡ

BOOL CMFC13View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC13View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC13View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC13View ���

#ifdef _DEBUG
void CMFC13View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC13View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC13Doc* CMFC13View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC13Doc)));
	return (CMFC13Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC13View ��Ϣ�������


void CMFC13View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
CClientDC dc(this);
	CMFC13Doc* pDoc = GetDocument();
	CString sss;
	sss.Format(_T("%s,%s"), pDoc->s, ss);
	dc.TextOutW(200, 200, sss);


	CView::OnLButtonDown(nFlags, point);
}
