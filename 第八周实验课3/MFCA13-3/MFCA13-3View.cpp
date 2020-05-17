
// MFCA13-3View.cpp : CMFCA133View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCA13-3.h"
#endif

#include "MFCA13-3Doc.h"
#include "MFCA13-3View.h"
#include "Mydlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCA133View

IMPLEMENT_DYNCREATE(CMFCA133View, CView)

BEGIN_MESSAGE_MAP(CMFCA133View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_popout, &CMFCA133View::Onpopout)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFCA133View ����/����

CMFCA133View::CMFCA133View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCA133View::~CMFCA133View()
{
}

BOOL CMFCA133View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCA133View ����

void CMFCA133View::OnDraw(CDC* /*pDC*/)
{
	CMFCA133Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCA133View ���

#ifdef _DEBUG
void CMFCA133View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCA133View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCA133Doc* CMFCA133View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCA133Doc)));
	return (CMFCA133Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCA133View ��Ϣ�������

void CMFCA133View::Onpopout()
{
	CMFCA133Doc* pDoc = GetDocument();
	Mydlg0 dlg;
	int t = dlg.DoModal();
	dlg.s1.InsertString(-1,pDoc->filename);
	// TODO: �ڴ���������������
}


void CMFCA133View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCA133Doc* pDoc = GetDocument();
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r = IDOK)
	{
		pDoc->filename = cfd.GetFileName();
		dc.TextOutW(200, 300, pDoc->filename);
	}
	
	CView::OnLButtonDblClk(nFlags, point);
}
