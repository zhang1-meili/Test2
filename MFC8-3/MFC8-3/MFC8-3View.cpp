
// MFC8-3View.cpp : CMFC83View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC8-3.h"
#endif

#include "MFC8-3Doc.h"
#include "MFC8-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC83View

IMPLEMENT_DYNCREATE(CMFC83View, CView)

BEGIN_MESSAGE_MAP(CMFC83View, CView)
	ON_COMMAND(ID_zhixian, &CMFC83View::Onzhixian)
	ON_COMMAND(ID_juxing, &CMFC83View::Onjuxing)
	ON_COMMAND(ID_tuoyuan, &CMFC83View::Ontuoyuan)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC83View ����/����

CMFC83View::CMFC83View()
{
	// TODO: �ڴ˴���ӹ������
	m_nd = 0;
	m_pt = 0;
}

CMFC83View::~CMFC83View()
{
}

BOOL CMFC83View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC83View ����

void CMFC83View::OnDraw(CDC* /*pDC*/)
{
	CMFC83Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC83View ���

#ifdef _DEBUG
void CMFC83View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC83View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC83Doc* CMFC83View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC83Doc)));
	return (CMFC83Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC83View ��Ϣ�������


void CMFC83View::Onzhixian()
{
	m_nd = 1;
	// TODO: �ڴ���������������
}


void CMFC83View::Onjuxing()
{
	m_nd = 2;
	// TODO: �ڴ���������������
}


void CMFC83View::Ontuoyuan()
{
	m_nd = 3;
	// TODO: �ڴ���������������
}


void CMFC83View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_pt = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC83View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	switch (m_nd)
	{case 1:
		dc.MoveTo(m_pt);
		dc.LineTo(point);
		break;
	case 2:
		dc.Rectangle(CRect(m_pt, point));
		break;
	case 3:
		dc.Ellipse(CRect(m_pt, point));
		break;
	default:
		break;
	}
	CView::OnLButtonUp(nFlags, point);
}
