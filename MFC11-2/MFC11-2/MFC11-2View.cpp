
// MFC11-2View.cpp : CMFC112View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC11-2.h"
#endif

#include "MFC11-2Doc.h"
#include "MFC11-2View.h"
#include "MyDlg0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC112View

IMPLEMENT_DYNCREATE(CMFC112View, CView)

BEGIN_MESSAGE_MAP(CMFC112View, CView)
	ON_COMMAND(ID_popout, &CMFC112View::Onpopout)
	
END_MESSAGE_MAP()

// CMFC112View ����/����

CMFC112View::CMFC112View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC112View::~CMFC112View()
{
}

BOOL CMFC112View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC112View ����

void CMFC112View::OnDraw(CDC* /*pDC*/)
{
	CMFC112Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC112View ���

#ifdef _DEBUG
void CMFC112View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC112View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC112Doc* CMFC112View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC112Doc)));
	return (CMFC112Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC112View ��Ϣ�������


void CMFC112View::Onpopout()
{
	MyDlg0 dlg;
	int t = dlg.DoModal();

	// TODO: �ڴ���������������
}


