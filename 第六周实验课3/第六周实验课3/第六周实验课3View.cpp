
// ������ʵ���3View.cpp : C������ʵ���3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ���3.h"
#endif

#include "������ʵ���3Doc.h"
#include "������ʵ���3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ���3View

IMPLEMENT_DYNCREATE(C������ʵ���3View, CView)

BEGIN_MESSAGE_MAP(C������ʵ���3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// C������ʵ���3View ����/����

C������ʵ���3View::C������ʵ���3View()
{
	// TODO: �ڴ˴���ӹ������
	i = 0;

}

C������ʵ���3View::~C������ʵ���3View()
{
}

BOOL C������ʵ���3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ���3View ����

void C������ʵ���3View::OnDraw(CDC* /*pDC*/)
{
	C������ʵ���3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	for (int i = 0; i < 6; i++) {
		dc.TextOutW(0 + 18 * i, 0, ss[i]);
	}
	for (int i = 6; i <12; i++) {
		dc.TextOutW(0 +18 * (i-6),20, ss[i]);
	}
	for (int i = 12; i <36; i++) {
		dc.TextOutW(0 + 18 * (i - 12), 40, ss[i]);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C������ʵ���3View ��ӡ

BOOL C������ʵ���3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C������ʵ���3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C������ʵ���3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C������ʵ���3View ���

#ifdef _DEBUG
void C������ʵ���3View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ���3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ���3Doc* C������ʵ���3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ���3Doc)));
	return (C������ʵ���3Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ���3View ��Ϣ�������


void C������ʵ���3View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ss[i] = (wchar_t)nChar;
	i++;
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}
