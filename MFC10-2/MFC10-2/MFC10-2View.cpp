
// MFC10-2View.cpp : CMFC102View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC10-2.h"
#endif

#include "MFC10-2Doc.h"
#include "MFC10-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC102View

IMPLEMENT_DYNCREATE(CMFC102View, CView)

BEGIN_MESSAGE_MAP(CMFC102View, CView)
	ON_WM_CREATE()
	ON_WM_CHAR()
	ON_WM_MBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC102View ����/����

CMFC102View::CMFC102View()
{
	// TODO: �ڴ˴���ӹ������
	i = 0;
	a = 0;
	flag = 1;

}

CMFC102View::~CMFC102View()
{
}

BOOL CMFC102View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC102View ����

void CMFC102View::OnDraw(CDC* pDC)
{
	CMFC102Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	for (int i = 0; i < 12; i++) {
		dc.TextOutW(0 + 35*i, 0, ss[i]);
	}
	
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC102View ���

#ifdef _DEBUG
void CMFC102View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC102View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC102Doc* CMFC102View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC102Doc)));
	return (CMFC102Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC102View ��Ϣ�������



void CMFC102View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CClientDC dc(this);
	if(flag==1){
	ss[i]= (wchar_t)nChar;
	i++;
	Invalidate();
	}
	if (flag == 0)
	{
		ss[a+1]= (wchar_t)nChar;
		Invalidate();	
	   
	}
	
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFC102View::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CView::OnMButtonDown(nFlags, point);
}


void CMFC102View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC102Doc* pDoc = GetDocument();
	CClientDC dc(this);
	
	point1.x = point.x;
	point1.y = point.y;
	a = point1.x /35;
	CString c,c2;
	c = ss[a];
	c2 = ss[a + 1];
	ss[a + 3] =c2;
	flag = 0;
}
