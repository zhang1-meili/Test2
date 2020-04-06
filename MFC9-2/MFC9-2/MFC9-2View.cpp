
// MFC9-2View.cpp : CMFC92View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC9-2.h"
#endif

#include "MFC9-2Doc.h"
#include "MFC9-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC92View

IMPLEMENT_DYNCREATE(CMFC92View, CView)

BEGIN_MESSAGE_MAP(CMFC92View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFC92View::OnFileOpen)
END_MESSAGE_MAP()

// CMFC92View ����/����

CMFC92View::CMFC92View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC92View::~CMFC92View()
{
}

BOOL CMFC92View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC92View ����

void CMFC92View::OnDraw(CDC* /*pDC*/)
{
	CMFC92Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC92View ���

#ifdef _DEBUG
void CMFC92View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC92View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC92Doc* CMFC92View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC92Doc)));
	return (CMFC92Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC92View ��Ϣ�������


void CMFC92View::OnFileOpen()
{
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	int w, h, sx, sy;
	if (r = IDOK)
	{
		CString filename = cfd.GetPathName();
		CImage img;
		img.Load(filename);
		{
			
			CRect rect;
			GetClientRect(&rect);
			float rect_ratio = 1.0*rect.Width() / rect.Height();
			float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
			if (rect_ratio > img_ratio) {
				h = rect.Height();
				w = img_ratio*h;
				sx = (rect.Width() - w) / 2;
				sy= 0;
			}
			else
			{
				w = rect.Width();
				h = w / img_ratio;
				sx = 0;
				sy = (rect.Height() - h) / 2;
			}
		}
		//img.Load(filename);
		
		img.Draw(dc.m_hDC, sx, sy, w, h);
	}

	// TODO: �ڴ���������������
}
