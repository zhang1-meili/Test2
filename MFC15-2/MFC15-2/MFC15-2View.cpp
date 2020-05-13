
// MFC15-2View.cpp : CMFC152View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CMFC152View 构造/析构

CMFC152View::CMFC152View()
{
	// TODO:  在此处添加构造代码

}

CMFC152View::~CMFC152View()
{
}

BOOL CMFC152View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC152View 绘制

void CMFC152View::OnDraw(CDC* /*pDC*/)
{
	CMFC152Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC152View 诊断

#ifdef _DEBUG
void CMFC152View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC152View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC152Doc* CMFC152View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC152Doc)));
	return (CMFC152Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC152View 消息处理程序


void CMFC152View::Onpopout()
{
	MYdlg dlg;
	int r = dlg.DoModal();
	// TODO:  在此添加命令处理程序代码
}
