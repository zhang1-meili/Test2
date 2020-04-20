
// MFC14-4View.cpp : CMFC144View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC14-4.h"
#endif

#include "MFC14-4Doc.h"
#include "MFC14-4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC144View

IMPLEMENT_DYNCREATE(CMFC144View, CView)

BEGIN_MESSAGE_MAP(CMFC144View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC144View 构造/析构

CMFC144View::CMFC144View()
{
	// TODO: 在此处添加构造代码
	point1.x = 200;
	point1.y = 300;

}

CMFC144View::~CMFC144View()
{
}

BOOL CMFC144View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC144View 绘制

void CMFC144View::OnDraw(CDC* /*pDC*/)
{
	CMFC144Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	rect.left = point1.x - 50;
	rect.top = point1.y - 60;
	rect.right = point1.x + 70;
	rect.bottom = point1.y + 80;
	dc.Ellipse(&rect);

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC144View 打印

BOOL CMFC144View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC144View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC144View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC144View 诊断

#ifdef _DEBUG
void CMFC144View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC144View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC144Doc* CMFC144View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC144Doc)));
	return (CMFC144Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC144View 消息处理程序


void CMFC144View::OnLButtonDown(UINT nFlags, CPoint point)
{
	//int red = 0, green = 0, blue = 0;
	int width = 1;
	int color = RGB(255, 0, 0);
	CClientDC dc(this);
	CRect rect1;
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (point.x >150 && point.x <270 && point.y>240&& point.y <380)
	{
		CPen newPen(PS_DASH, width, color);
		CPen *oldPen = dc.SelectObject(&newPen);
		rect1.left = point1.x - 50;
		rect1.top = point1.y - 60;
		rect1.right = point1.x + 70;
		rect1.bottom = point1.y + 80;
		dc.Rectangle(&rect1);
		dc.SelectObject(oldPen);
	}
	dc.Ellipse(&rect);
	CView::OnLButtonDown(nFlags, point);
}
