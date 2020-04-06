
// MFC9-1View.cpp : CMFC91View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC9-1.h"
#endif

#include "MFC9-1Doc.h"
#include "MFC9-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC91View

IMPLEMENT_DYNCREATE(CMFC91View, CView)

BEGIN_MESSAGE_MAP(CMFC91View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMFC91View::OnFileOpen)
END_MESSAGE_MAP()

// CMFC91View ����/����

CMFC91View::CMFC91View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC91View::~CMFC91View()
{
}

BOOL CMFC91View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC91View ����

void CMFC91View::OnDraw(CDC* /*pDC*/)
{
	CMFC91Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC91View ��ӡ

BOOL CMFC91View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC91View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC91View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC91View ���

#ifdef _DEBUG
void CMFC91View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC91View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC91Doc* CMFC91View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC91Doc)));
	return (CMFC91Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC91View ��Ϣ�������


void CMFC91View::OnFileOpen()
{
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r = IDOK)
	{
		CString filename = cfd.GetPathName();
		dc.TextOutW(200, 300, filename);
	}
	// TODO: �ڴ���������������
}
