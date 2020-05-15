
// 第四周实验课-1View.cpp : C第四周实验课1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第四周实验课-1.h"
#endif

#include "第四周实验课-1Doc.h"
#include "第四周实验课-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第四周实验课1View

IMPLEMENT_DYNCREATE(C第四周实验课1View, CView)

BEGIN_MESSAGE_MAP(C第四周实验课1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C第四周实验课1View 构造/析构

C第四周实验课1View::C第四周实验课1View()
{
	// TODO: 在此处添加构造代码

}

C第四周实验课1View::~C第四周实验课1View()
{
}

BOOL C第四周实验课1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第四周实验课1View 绘制

void C第四周实验课1View::OnDraw(CDC* /*pDC*/)
{
	C第四周实验课1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C第四周实验课1View 打印

BOOL C第四周实验课1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第四周实验课1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第四周实验课1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第四周实验课1View 诊断

#ifdef _DEBUG
void C第四周实验课1View::AssertValid() const
{
	CView::AssertValid();
}

void C第四周实验课1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第四周实验课1Doc* C第四周实验课1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第四周实验课1Doc)));
	return (C第四周实验课1Doc*)m_pDocument;
}
#endif //_DEBUG


// C第四周实验课1View 消息处理程序


void C第四周实验课1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第四周实验课1Doc* pDoc = GetDocument();
	pDoc->x1.x = point.x;
	CView::OnLButtonDown(nFlags, point);
}


void C第四周实验课1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第四周实验课1Doc* pDoc = GetDocument();
	pDoc->x2.x = point.x;
	CClientDC dc(this);
	CString s1, s2;
	s1.Format(_T("%d"), pDoc->count);
	int x3;
	x3 = (pDoc->x2.x - pDoc->x1.x) / pDoc->count;
	s2.Format(_T("%d"), x3);
	dc.TextOutW(20, 20, s1);
	dc.TextOutW(20, 40, s2);
	pDoc->count = 0;
	CView::OnLButtonUp(nFlags, point);

}


void C第四周实验课1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第四周实验课1Doc* pDoc = GetDocument();
	pDoc->count= pDoc->count+1;
	CView::OnMouseMove(nFlags, point);
}
