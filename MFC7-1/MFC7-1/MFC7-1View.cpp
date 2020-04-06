
// MFC7-1View.cpp : CMFC71View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC7-1.h"
#endif

#include "MFC7-1Doc.h"
#include "MFC7-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC71View

IMPLEMENT_DYNCREATE(CMFC71View, CView)

BEGIN_MESSAGE_MAP(CMFC71View, CView)
	ON_COMMAND(ID_showYuan, &CMFC71View::Onshowyuan)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC71View ����/����

CMFC71View::CMFC71View()
{
	// TODO: �ڴ˴���ӹ������
	set = false;
	a=10;
	


}

CMFC71View::~CMFC71View()
{
}

BOOL CMFC71View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC71View ����

void CMFC71View::OnDraw(CDC* pDC)
{
	CMFC71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	SetTimer(a, 1500, NULL);
	if (set==true) {
		int red = 0, green = 0, blue = 0;
		int width =2;
		for (int s = 0; s < 8;s++){
		int color = RGB(red, green, blue);
		CPen newPen(PS_SOLID,width,color);
		CPen *oldPen = pDC->SelectObject(&newPen);
		CRect clientRec;//�������
		GetClientRect(&clientRec);//ȡ�ÿͻ�����С
		m_pt.x = (clientRec.right - clientRec.left) / 2;
		m_pt.y = (clientRec.bottom - clientRec.top) / 2;
		pDC->Ellipse(m_pt.x - a, m_pt.y + a, m_pt.x + a, m_pt.y - a);
		pDC->SelectObject(oldPen);
		red += 32;
		green += 16;
		blue += 8;
		}
	}

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC71View ���

#ifdef _DEBUG
void CMFC71View::AssertValid() const
{
	CView::AssertValid();
}   

void CMFC71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC71Doc* CMFC71View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC71Doc)));
	return (CMFC71Doc*)m_pDocument;
}
#endif //_DEBUG 


// CMFC71View ��Ϣ�������


void CMFC71View::Onshowyuan()
{
	
	set = true;
	CClientDC dc(this);
	CRect clientRec;
	GetClientRect(&clientRec);
	m_pt.x = (clientRec.right - clientRec.left) / 2;
	m_pt.y = (clientRec.bottom - clientRec.top) / 2;
	dc.Ellipse(m_pt.x - a, m_pt.y + a, m_pt.x + a, m_pt.y - a);

	// TODO: �ڴ���������������
}


void CMFC71View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	a += 2;
	Invalidate();
	CView::OnTimer(nIDEvent);

}
