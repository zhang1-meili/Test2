
// MFC11-1View.cpp : CMFC111View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC11-1.h"
#endif

#include "MFC11-1Doc.h"
#include "MFC11-1View.h"
#include "MyDlg0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC111View

IMPLEMENT_DYNCREATE(CMFC111View, CView)

BEGIN_MESSAGE_MAP(CMFC111View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_putout, &CMFC111View::Onputout)
END_MESSAGE_MAP()

// CMFC111View ����/����

CMFC111View::CMFC111View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC111View::~CMFC111View()
{
}

BOOL CMFC111View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC111View ����

void CMFC111View::OnDraw(CDC* /*pDC*/)
{
	CMFC111Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC111View ��ӡ

BOOL CMFC111View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC111View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC111View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC111View ���

#ifdef _DEBUG
void CMFC111View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC111View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC111Doc* CMFC111View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC111Doc)));
	return (CMFC111Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC111View ��Ϣ�������


void CMFC111View::Onputout()
{ 

	MyDlg0 dlg = new MyDlg0();
	int t = dlg.DoModal();
	if (t = IDOK) {
		CString s;
		CClientDC dc(this);
		s.Format(_T("�����˳��Ի���"));
		dc.TextOutW(200,200,s);
		
	}
	// TODO: �ڴ���������������
}
