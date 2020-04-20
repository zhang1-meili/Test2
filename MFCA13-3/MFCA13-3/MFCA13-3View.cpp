
// MFCA13-3View.cpp : CMFCA133View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCA13-3.h"
#endif

#include "MFCA13-3Doc.h"
#include "MFCA13-3View.h"
#include "Mydlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCA133View

IMPLEMENT_DYNCREATE(CMFCA133View, CView)

BEGIN_MESSAGE_MAP(CMFCA133View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_popout, &CMFCA133View::Onpopout)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFCA133View 构造/析构

CMFCA133View::CMFCA133View()
{
	// TODO: 在此处添加构造代码

}

CMFCA133View::~CMFCA133View()
{
}

BOOL CMFCA133View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCA133View 绘制

void CMFCA133View::OnDraw(CDC* /*pDC*/)
{
	CMFCA133Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCA133View 诊断

#ifdef _DEBUG
void CMFCA133View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCA133View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCA133Doc* CMFCA133View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCA133Doc)));
	return (CMFCA133Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCA133View 消息处理程序

void CMFCA133View::Onpopout()
{
	CMFCA133Doc* pDoc = GetDocument();
	Mydlg0 dlg;
	int t = dlg.DoModal();
	dlg.s1.InsertString(-1,pDoc->filename);
	// TODO: 在此添加命令处理程序代码
}


void CMFCA133View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCA133Doc* pDoc = GetDocument();
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r = IDOK)
	{
		pDoc->filename = cfd.GetFileName();
		dc.TextOutW(200, 300, pDoc->filename);
	}
	
	CView::OnLButtonDblClk(nFlags, point);
}
