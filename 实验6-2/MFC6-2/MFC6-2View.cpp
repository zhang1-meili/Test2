
// MFC6-2View.cpp : CMFC62View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC6-2.h"
#endif

#include "MFC6-2Doc.h"
#include "MFC6-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC62View

IMPLEMENT_DYNCREATE(CMFC62View, CView)

BEGIN_MESSAGE_MAP(CMFC62View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC62View ����/����

CMFC62View::CMFC62View()
{
	// TODO: �ڴ˴���ӹ������
	set = true;
	N = 5;
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 20, 20);
		cr.Add(rect);
	}
}

CMFC62View::~CMFC62View()
{
}

BOOL CMFC62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC62View ����

void CMFC62View::OnDraw(CDC* pDC)
{
	CMFC62Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set) {
		for (int i = 0; i < N; i++) {
			SetTimer(i, rand() % 400 + 100, NULL);
			set = false;
		}

	}
	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC62View ���

#ifdef _DEBUG
void CMFC62View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC62View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC62Doc* CMFC62View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC62Doc)));
	return (CMFC62Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC62View ��Ϣ�������


void CMFC62View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int i = nIDEvent;
	cr[i].top += 10;
	cr[i].bottom += 10;
	Invalidate();
	CView::OnTimer(nIDEvent);
}
