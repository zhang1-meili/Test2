
// �ۺ�2-2View.cpp : C�ۺ�22View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ۺ�2-2.h"
#endif

#include "�ۺ�2-2Doc.h"
#include "�ۺ�2-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�22View

IMPLEMENT_DYNCREATE(C�ۺ�22View, CView)

BEGIN_MESSAGE_MAP(C�ۺ�22View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C�ۺ�22View ����/����

C�ۺ�22View::C�ۺ�22View()
{
	// TODO: �ڴ˴���ӹ������

}

C�ۺ�22View::~C�ۺ�22View()
{
}

BOOL C�ۺ�22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ۺ�22View ����

void C�ۺ�22View::OnDraw(CDC* /*pDC*/)
{
	C�ۺ�22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ۺ�22View ��ӡ

BOOL C�ۺ�22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ۺ�22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ۺ�22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ۺ�22View ���

#ifdef _DEBUG
void C�ۺ�22View::AssertValid() const
{
	CView::AssertValid();
}

void C�ۺ�22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ۺ�22Doc* C�ۺ�22View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ۺ�22Doc)));
	return (C�ۺ�22Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ۺ�22View ��Ϣ�������
