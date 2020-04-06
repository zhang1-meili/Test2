
// MFC10-1View.cpp : CMFC101View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC10-1.h"
#endif

#include "MFC10-1Doc.h"
#include "MFC10-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC101View

IMPLEMENT_DYNCREATE(CMFC101View, CView)

BEGIN_MESSAGE_MAP(CMFC101View, CView)
	ON_WM_CHAR()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC101View ����/����

CMFC101View::CMFC101View()
{
	// TODO: �ڴ˴���ӹ������
}

CMFC101View::~CMFC101View()
{
}

BOOL CMFC101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC101View ����

void CMFC101View::OnDraw(CDC* pDC)
{
	CMFC101Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect c1(300, 300, 500, 200);
	pDC->Rectangle(&c1);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC101View ���

#ifdef _DEBUG
void CMFC101View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC101View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC101Doc* CMFC101View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC101Doc)));
	return (CMFC101Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC101View ��Ϣ�������


void CMFC101View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CClientDC viewDC(this);
	TEXTMETRIC txtm;
	viewDC.GetTextMetrics(&txtm);

	if (0x0D == nChar) {
		m_strLen.Empty();
		m_point.y += txtm.tmHeight;
		SetCaretPos(m_point);
	}
	else if (0x08 == nChar) {
		COLORREF precolor = viewDC.SetTextColor(viewDC.GetBkColor());

		viewDC.TextOutW(m_point.x, m_point.y, m_strLen);
		m_strLen = m_strLen.Left(m_strLen.GetLength() - 1);

	}
	else {
		//�ַ�����ת��??CString??str;?
		CString str;
		str.Format(_T("%c"), nChar);
		m_strLen += str;

	}

	CSize m_size = viewDC.GetTextExtent(m_strLen);
	CPoint point;

	point.x = m_point.x + m_size.cx;
	point.y = m_point.y;

	SetCaretPos(point);

	viewDC.TextOut(m_point.x, m_point.y, m_strLen);

	CView::OnChar(nChar, nRepCnt, nFlags);
}


int CMFC101View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	//����ʵ���겢��ʾ?
	CreateSolidCaret(tm.tmAveCharWidth / 8, tm.tmHeight);
	ShowCaret();

	// TODO:  �ڴ������ר�õĴ�������

	return 0;
}


void CMFC101View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCaretPos(point);
	m_point = point;
	CView::OnLButtonDown(nFlags, point);
}
