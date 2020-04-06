
// MFC8-2View.cpp : CMFC82View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC8-2.h"
#endif

#include "MFC8-2Doc.h"
#include "MFC8-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC82View

IMPLEMENT_DYNCREATE(CMFC82View, CView)

BEGIN_MESSAGE_MAP(CMFC82View, CView)
	ON_COMMAND(ID_showbitmap, &CMFC82View::Onshowbitmap)
END_MESSAGE_MAP()

// CMFC82View ����/����

CMFC82View::CMFC82View()
{
	// TODO: �ڴ˴���ӹ������
	BITMAP bm;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&bm);
	m_nWidth = bm.bmWidth;
	m_nHeight = bm.bmHeight;


}

CMFC82View::~CMFC82View()
{
}

BOOL CMFC82View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC82View ����

void CMFC82View::OnDraw(CDC* pDC)
{
	CMFC82Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	//CClientDC dc(this);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC82View ���

#ifdef _DEBUG
void CMFC82View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC82View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC82Doc* CMFC82View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC82Doc)));
	return (CMFC82Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC82View ��Ϣ�������


void CMFC82View::Onshowbitmap()
{
	

	// TODO: �ڴ���������������
}
