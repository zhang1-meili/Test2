
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


int CMFC102View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	//����ʵ���겢��ʾ?
	CreateSolidCaret(tm.tmAveCharWidth/8, tm.tmHeight);
	ShowCaret();
	// TODO:  �ڴ������ר�õĴ�������

	return 0;
}


void CMFC102View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC viewDC(this);
	TEXTMETRIC txtm;
	viewDC.GetTextMetrics(&txtm);
	
	if (0x0D== nChar) {
		m_strLen.Empty();
		m_point.y+=txtm.tmHeight;
		SetCaretPos(m_point);
	}
	else if (0x08== nChar) {
		COLORREF precolor = viewDC.SetTextColor(viewDC.GetBkColor());

		viewDC.TextOutW(m_point.x, m_point.y,m_strLen);
		m_strLen = m_strLen.Left(m_strLen.GetLength() - 1);
		
	}
	else {
		//�ַ�����ת��??CString??str;?
		CString str;
		str.Format(_T("%c"), nChar);
		m_strLen+=str;
		
	}

	CSize m_size = viewDC.GetTextExtent(m_strLen);
	CPoint point;

	point.x = m_point.x + m_size.cx;
	point.y = m_point.y;

	SetCaretPos(point);

	viewDC.TextOut(m_point.x, m_point.y, m_strLen);
	
	
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
	SetCaretPos(point);
	m_point = point;
	CView::OnLButtonDown(nFlags, point);
}
