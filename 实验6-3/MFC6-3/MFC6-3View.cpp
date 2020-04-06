
// MFC6-3View.cpp : CMFC63View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC6-3.h"
#endif

#include "MFC6-3Doc.h"
#include "MFC6-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC63View

IMPLEMENT_DYNCREATE(CMFC63View, CView)

BEGIN_MESSAGE_MAP(CMFC63View, CView)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC63View ����/����

CMFC63View::CMFC63View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC63View::~CMFC63View()
{
}

BOOL CMFC63View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC63View ����

void CMFC63View::OnDraw(CDC* pDC)
{
	CMFC63Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->m_tagRect);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC63View ���

#ifdef _DEBUG
void CMFC63View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC63View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC63Doc* CMFC63View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC63Doc)));
	return (CMFC63Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC63View ��Ϣ�������


void CMFC63View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC63Doc* pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->m_tagRect.left > 0) {
			pDoc->m_tagRect.left -= 5;
			pDoc->m_tagRect.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->m_tagRect.right <=(clientRec.right- clientRec.left) ){
			pDoc->m_tagRect.left += 5;
			pDoc->m_tagRect.right += 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->m_tagRect.bottom > 0) {
			pDoc->m_tagRect.top+= 5;
			pDoc->m_tagRect.bottom+= 5;
		}break;
	case VK_UP:
		if (pDoc->m_tagRect.top > 0) {
			pDoc->m_tagRect.top -= 5;
			pDoc->m_tagRect.bottom -= 5;
		}break;
	}
	

	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFC63View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC63Doc* pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);
	switch (nChar)
	{
	case 'L':
		if (pDoc->m_tagRect.top > 0) {
			pDoc->m_tagRect.top -= 10;
			pDoc->m_tagRect.left -=10;
			pDoc->m_tagRect.right = 350;
			pDoc->m_tagRect.bottom = 300;
		}
		break;
	case 'R':
		if (pDoc->m_tagRect.bottom > 0) {
			pDoc->m_tagRect.left = 30;
			pDoc->m_tagRect.top = 30;
			pDoc->m_tagRect.right -= 20;
			pDoc->m_tagRect.bottom -= 20;
		}
		break;
		CView::OnChar(nChar, nRepCnt, nFlags);
	}
}

	void CMFC63View::OnLButtonDown(UINT nFlags, CPoint point)
	{
		// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
		CMFC63Doc* pDoc = GetDocument();
		pDoc->m_tagRect.left = 30;
		pDoc->m_tagRect.top = 30;
		pDoc->m_tagRect.right = 350;
		pDoc->m_tagRect.bottom = 300;
		CView::OnLButtonDown(nFlags, point);
	}
