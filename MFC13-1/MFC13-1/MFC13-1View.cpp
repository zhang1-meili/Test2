
// MFC13-1View.cpp : CMFC131View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC13-1.h"
#endif

#include "MFC13-1Doc.h"
#include "MFC13-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC131View

IMPLEMENT_DYNCREATE(CMFC131View, CView)

BEGIN_MESSAGE_MAP(CMFC131View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC131View ����/����

CMFC131View::CMFC131View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC131View::~CMFC131View()
{
}

BOOL CMFC131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC131View ����

void CMFC131View::OnDraw(CDC* /*pDC*/)
{
	CMFC131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC131View ��ӡ

BOOL CMFC131View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC131View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC131View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC131View ���

#ifdef _DEBUG
void CMFC131View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC131View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC131Doc* CMFC131View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC131Doc)));
	return (CMFC131Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC131View ��Ϣ�������


void CMFC131View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r = IDOK)
	{
		CString filename = cfd.GetPathName();
		dc.TextOutW(200, 300, filename);
	}



	CView::OnLButtonDblClk(nFlags, point);
}
