
// MFC15-2View.cpp : CMFC152View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC15-2.h"
#endif

#include "MFC15-2Doc.h"
#include "MFC15-2View.h"
#include "MYdlg.h"
#include <fstream>
#include<string>
#include<iostream>
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC152View

IMPLEMENT_DYNCREATE(CMFC152View, CView)

BEGIN_MESSAGE_MAP(CMFC152View, CView)
	//ON_BN_CLICKED(IDC_BUTTON1, &CMFC152View::OnBnClickedButton1)
	ON_COMMAND(ID_popout, &CMFC152View::Onpopout)
END_MESSAGE_MAP()

// CMFC152View ����/����

CMFC152View::CMFC152View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC152View::~CMFC152View()
{
}

BOOL CMFC152View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC152View ����

void CMFC152View::OnDraw(CDC* /*pDC*/)
{
	CMFC152Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC152View ���

#ifdef _DEBUG
void CMFC152View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC152View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC152Doc* CMFC152View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC152Doc)));
	return (CMFC152Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC152View ��Ϣ�������


void CMFC152View::Onpopout()
{
	MYdlg dlg;
	int r = dlg.DoModal();
	// TODO:  �ڴ���������������
}
