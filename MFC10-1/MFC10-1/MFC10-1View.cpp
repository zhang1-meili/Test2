
// MFC10-1View.cpp : CMFC101View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC10-1.h"
#endif

#include "MFC10-1Doc.h"
#include "MFC10-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC101View

IMPLEMENT_DYNCREATE(CMFC101View, CView)

BEGIN_MESSAGE_MAP(CMFC101View, CView)
	ON_WM_CHAR()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC101View 构造/析构

CMFC101View::CMFC101View()
{
	// TODO: 在此处添加构造代码
}

CMFC101View::~CMFC101View()
{
}

BOOL CMFC101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC101View 绘制

void CMFC101View::OnDraw(CDC* pDC)
{
	CMFC101Doc* pDoc = GetDocument();
	CRect cr;
	cr.top = 20; cr.left = 20;
	cr.bottom = 100; cr.right = 300;
	CClientDC dc(this);
	dc.Rectangle(cr);
	dc.TextOutW(21, 50, pDoc->s);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC101View 诊断

#ifdef _DEBUG
void CMFC101View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC101View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC101Doc* CMFC101View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC101Doc)));
	return (CMFC101Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC101View 消息处理程序


void CMFC101View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CMFC101Doc* pDoc = GetDocument();
	CString str;
	pDoc->s += (wchar_t)nChar;
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}


/*int CMFC101View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	//创建实体光标并显示?
	CreateSolidCaret(tm.tmAveCharWidth / 8, tm.tmHeight);
	ShowCaret();

	// TODO:  在此添加您专用的创建代码

	return 0;
}


void CMFC101View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCaretPos(point);
	m_point = point;
	CView::OnLButtonDown(nFlags, point);
}
*/