
// MFC15-1View.cpp : CMFC151View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC15-1.h"
#endif

#include "MFC15-1Doc.h"
#include "MFC15-1View.h"
#include <fstream>
#include<string>
#include<iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC151View

IMPLEMENT_DYNCREATE(CMFC151View, CView)

BEGIN_MESSAGE_MAP(CMFC151View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popout, &CMFC151View::Onpopout)
END_MESSAGE_MAP()

// CMFC151View ����/����

CMFC151View::CMFC151View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC151View::~CMFC151View()
{
}

BOOL CMFC151View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC151View ����

void CMFC151View::OnDraw(CDC* /*pDC*/)
{
	CMFC151Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC151View ��ӡ

BOOL CMFC151View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC151View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC151View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC151View ���

#ifdef _DEBUG
void CMFC151View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC151View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC151Doc* CMFC151View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC151Doc)));
	return (CMFC151Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC151View ��Ϣ�������


void CMFC151View::Onpopout()

{

	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
    CString filename;

	if (r = IDOK)
	{
		 filename = cfd.GetPathName();
		dc.TextOutW(200, 300, filename);
		ofstream ofs("D:\\abc.txt");
		std::wstring ws(filename);
		std::string s;
		s.assign(ws.begin(), ws.end());
		ofs << s<<endl;
	}
	// TODO: �ڴ���������������
}
