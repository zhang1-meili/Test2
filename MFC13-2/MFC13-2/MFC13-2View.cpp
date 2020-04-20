
// MFC13-2View.cpp : CMFC132View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC13-2.h"
#endif

#include "MFC13-2Doc.h"
#include "MFC13-2View.h"
#include "Mydlgo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC132View

IMPLEMENT_DYNCREATE(CMFC132View, CView)

BEGIN_MESSAGE_MAP(CMFC132View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_popout, &CMFC132View::Onpopout)
END_MESSAGE_MAP()

// CMFC132View ����/����

CMFC132View::CMFC132View()
{
	//filename = "";
	// TODO: �ڴ˴���ӹ������

}

CMFC132View::~CMFC132View()
{
}

BOOL CMFC132View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC132View ����

void CMFC132View::OnDraw(CDC* /*pDC*/)
{
	CMFC132Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC132View ��ӡ

BOOL CMFC132View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC132View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC132View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC132View ���

#ifdef _DEBUG
void CMFC132View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC132View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC132Doc* CMFC132View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC132Doc)));
	return (CMFC132Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC132View ��Ϣ�������


void CMFC132View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC132Doc* pDoc = GetDocument();
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	//CClientDC dc(this);
	if (r = IDOK)
	{
	pDoc-> filename = cfd.GetFileName();
     GetDC()->TextOutW(200, 300,pDoc-> filename);
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFC132View::Onpopout()
{
	CMFC132Doc* pDoc = GetDocument();
	Mydlgo dlg;
	int t = dlg.DoModal();
	this->UpdateData(true);
	dlg.s1=pDoc->filename;
	UpdateData(false);
	// TODO: �ڴ���������������
}
