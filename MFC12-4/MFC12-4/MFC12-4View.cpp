
// MFC12-4View.cpp : CMFC124View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC12-4.h"
#endif

#include "MFC12-4Doc.h"
#include "MFC12-4View.h"
#include "Mydlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC124View

IMPLEMENT_DYNCREATE(CMFC124View, CView)

BEGIN_MESSAGE_MAP(CMFC124View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popout, &CMFC124View::Onpopout)
	ON_BN_CLICKED(IDOK, &CMFC124View::OnBnClickedOk)
END_MESSAGE_MAP()

// CMFC124View ����/����

CMFC124View::CMFC124View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC124View::~CMFC124View()
{
}

BOOL CMFC124View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC124View ����

void CMFC124View::OnDraw(CDC* /*pDC*/)
{
	CMFC124Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC124View ��ӡ

BOOL CMFC124View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC124View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC124View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC124View ���

#ifdef _DEBUG
void CMFC124View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC124View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC124Doc* CMFC124View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC124Doc)));
	return (CMFC124Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC124View ��Ϣ�������


void CMFC124View::Onpopout()
{
	Mydlg0 dlg;
	int t = dlg.DoModal();


	// TODO: �ڴ���������������
}


void CMFC124View::OnBnClickedOk()
{

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}



