
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
	ON_WM_LBUTTONDOWN()
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
	
	CRect c1(400, 400, 500, 500);
	CRect c2(500, 500, 600, 600);
	CRect c3(300, 300, 400, 400);
	pDC->Rectangle(&c1);
	pDC->Rectangle(&c2);
	pDC->Rectangle(&c3);
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


void CMFC5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	
	int t = rand() % 100;
	CString s;
	s.Format(_T("%d"), t);
	CString ss;
	ss.Format(_T("%d"),a+b);
	if (point.x > 400 && point.x < 500 && point.y>400 && point.y < 500)
	{
		dc.TextOutW(point.x, point.y, s);
		a = t;
	}
	else if (point.x > 500 && point.x < 600 && point.y>500 && point.y < 600)
	{
		dc.TextOutW(point.x, point.y, s);
		b = t;
	}
	else if (point.x > 300 && point.x < 400 && point.y>300 && point.y <400)
		dc.TextOutW(point.x, point.y, ss);
	else 
	{ 
		CString s1; 
		s1.Format(_T("��Ч"));
		dc.TextOutW(point.x, point.y, s1);
	}
	CView::OnLButtonDown(nFlags, point);
	
}
