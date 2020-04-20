
// MFC12-1View.cpp : CMFC121View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC12-1.h"
#endif

#include "MFC12-1Doc.h"
#include "MFC12-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC121View

IMPLEMENT_DYNCREATE(CMFC121View, CView)

BEGIN_MESSAGE_MAP(CMFC121View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC121View 构造/析构

CMFC121View::CMFC121View()
{
	// TODO: 在此处添加构造代码
	set = false;
	point1.x = 200;
	point1.y = 300;

}

CMFC121View::~CMFC121View()
{
}

BOOL CMFC121View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC121View 绘制

void CMFC121View::OnDraw(CDC* /*pDC*/)
{
	CMFC121Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	rect.left = point1.x - 50;
	rect.top = point1.y - 60;
	rect.right = point1.x + 70;
	rect.bottom = point1.y + 80;
	dc.Rectangle(&rect);
	// TODO: 在此处为.y.
}

// CMFC121View 诊断

#ifdef _DEBUG
void CMFC121View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC121View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC121Doc* CMFC121View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC121Doc)));
	return (CMFC121Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC121View 消息处理程序


void CMFC121View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = true;

	CView::OnLButtonDown(nFlags, point);
}


void CMFC121View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = false;
	CView::OnLButtonUp(nFlags, point);
}


void CMFC121View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (set) {
		point1 = point;
		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}
