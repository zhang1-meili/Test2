
// MFC8-1View.cpp : CMFC81View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC8-1.h"
#endif

#include "MFC8-1Doc.h"
#include "MFC8-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC81View

IMPLEMENT_DYNCREATE(CMFC81View, CView)

BEGIN_MESSAGE_MAP(CMFC81View, CView)
	ON_COMMAND(ID_SHOWNAME, &CMFC81View::OnShowname)
END_MESSAGE_MAP()

// CMFC81View ����/����

CMFC81View::CMFC81View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC81View::~CMFC81View()
{
}

BOOL CMFC81View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC81View ����

void CMFC81View::OnDraw(CDC* /*pDC*/)
{
	CMFC81Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC81View ���

#ifdef _DEBUG
void CMFC81View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC81View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC81Doc* CMFC81View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC81Doc)));
	return (CMFC81Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC81View ��Ϣ�������


void CMFC81View::OnShowname()
{
	CString s = _T("��˼��");
	CClientDC dc(this);
	dc.TextOutW(200, 300, s);
	// TODO: �ڴ���������������

}