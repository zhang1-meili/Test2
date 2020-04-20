
// MFC14-1View.cpp : CMFC141View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC14-1.h"
#endif

#include "MFC14-1Doc.h"
#include "MFC14-1View.h"
#include "MyDlg0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC141View

IMPLEMENT_DYNCREATE(CMFC141View, CView)

BEGIN_MESSAGE_MAP(CMFC141View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popout, &CMFC141View::Onpopout)
END_MESSAGE_MAP()

// CMFC141View ����/����

CMFC141View::CMFC141View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC141View::~CMFC141View()
{
}

BOOL CMFC141View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC141View ����

void CMFC141View::OnDraw(CDC* /*pDC*/)
{
	CMFC141Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC141View ��ӡ

BOOL CMFC141View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC141View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC141View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC141View ���

#ifdef _DEBUG
void CMFC141View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC141View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC141Doc* CMFC141View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC141Doc)));
	return (CMFC141Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC141View ��Ϣ�������


void CMFC141View::Onpopout()
{
	MyDlg0 dlg;
	int t = dlg.DoModal();

	// TODO: �ڴ���������������
}
