
// MFC12-3View.cpp : CMFC123View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC12-3.h"
#endif

#include "MFC12-3Doc.h"
#include "MFC12-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC123View

IMPLEMENT_DYNCREATE(CMFC123View, CView)

BEGIN_MESSAGE_MAP(CMFC123View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC123View 构造/析构

CMFC123View::CMFC123View()
{
	set = false;
	// TODO: 在此处添加构造代码

}

CMFC123View::~CMFC123View()
{
}

BOOL CMFC123View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC123View 绘制

void CMFC123View::OnDraw(CDC* pDC)
{
	CMFC123Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
  
	if (!pDoc)
		return;
	pDC->Ellipse(pDoc->rect);

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC123View 打印

BOOL CMFC123View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC123View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC123View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC123View 诊断

#ifdef _DEBUG
void CMFC123View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC123View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC123Doc* CMFC123View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC123Doc)));
	return (CMFC123Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC123View 消息处理程序


void CMFC123View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	KillTimer(2);
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFC123View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMFC123Doc* pDoc = GetDocument();
	CClientDC dc(this);
	SetTimer(2, 1000, NULL);
	set = true;
	if (set == true) {
		dc.Ellipse(pDoc->rect);
	}
	
	CView::OnLButtonDown(nFlags, point);
}


void CMFC123View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC123Doc* pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (pDoc->rect.right>clientRec.right ) {
		pDoc->rect.left -= 20;
		pDoc->rect.right -= 20;
		Invalidate();

	}
	else{
		pDoc->rect.left+= 20;
		pDoc->rect.right += 20;
		Invalidate();
	}
	CView::OnTimer(nIDEvent);
}
