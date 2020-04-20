
// MFC14-3View.cpp : CMFC143View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC14-3.h"
#endif

#include "MFC14-3Doc.h"
#include "MFC14-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC143View

IMPLEMENT_DYNCREATE(CMFC143View, CView)

BEGIN_MESSAGE_MAP(CMFC143View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC143View 构造/析构

CMFC143View::CMFC143View()
{
	// TODO: 
	set = false;
	point1.x = 200;
	point1.y = 300;

}

CMFC143View::~CMFC143View()
{
}

BOOL CMFC143View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC143View 绘制

void CMFC143View::OnDraw(CDC* pDC)
{
	CMFC143Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	rect.left = point1.x - 50;
	rect.top = point1.y - 60;
	rect.right = point1.x +70;
	rect.bottom = point1.y + 80;
	dc.Ellipse(&rect);

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC143View 打印

BOOL CMFC143View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC143View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC143View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC143View 诊断

#ifdef _DEBUG
void CMFC143View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC143View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC143Doc* CMFC143View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC143Doc)));
	return (CMFC143Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC143View 消息处理程序


void CMFC143View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC143Doc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);
	if(set){
	point1 = point;
	Invalidate();
}
	CView::OnMouseMove(nFlags, point);
}


void CMFC143View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = true;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC143View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = false;
	CView::OnLButtonUp(nFlags, point);
}
