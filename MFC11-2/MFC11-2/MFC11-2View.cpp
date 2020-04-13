
// MFC11-2View.cpp : CMFC112View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC11-2.h"
#endif

#include "MFC11-2Doc.h"
#include "MFC11-2View.h"
#include "MyDlg0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC112View

IMPLEMENT_DYNCREATE(CMFC112View, CView)

BEGIN_MESSAGE_MAP(CMFC112View, CView)
	ON_COMMAND(ID_popout, &CMFC112View::Onpopout)
	
END_MESSAGE_MAP()

// CMFC112View 构造/析构

CMFC112View::CMFC112View()
{
	// TODO: 在此处添加构造代码

}

CMFC112View::~CMFC112View()
{
}

BOOL CMFC112View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC112View 绘制

void CMFC112View::OnDraw(CDC* /*pDC*/)
{
	CMFC112Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC112View 诊断

#ifdef _DEBUG
void CMFC112View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC112View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC112Doc* CMFC112View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC112Doc)));
	return (CMFC112Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC112View 消息处理程序


void CMFC112View::Onpopout()
{
	MyDlg0 dlg;
	int t = dlg.DoModal();

	// TODO: 在此添加命令处理程序代码
}


