
// MFC14-2View.cpp : CMFC142View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC14-2.h"
#endif

#include "MFC14-2Doc.h"
#include "MFC14-2View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC142View

IMPLEMENT_DYNCREATE(CMFC142View, CView)

BEGIN_MESSAGE_MAP(CMFC142View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popout, &CMFC142View::Onpopout)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC142View 构造/析构

CMFC142View::CMFC142View()
{
	// TODO: 在此处添加构造代码

}

CMFC142View::~CMFC142View()
{
}

BOOL CMFC142View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC142View 绘制

void CMFC142View::OnDraw(CDC* pDC)
{
	
	CPoint point;
	CMFC142Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(rect);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC142View 打印

BOOL CMFC142View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC142View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC142View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC142View 诊断

#ifdef _DEBUG
void CMFC142View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC142View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC142Doc* CMFC142View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC142Doc)));
	return (CMFC142Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC142View 消息处理程序




void CMFC142View::Onpopout()
{
	CRect cr;
	MyDlg0 dlg;
	CPoint point;
	int t = dlg.DoModal();
	if (t = IDOK) {
		r= dlg.r1;
		R = dlg.r2;
	}

	// TODO: 在此添加命令处理程序代码
}


void CMFC142View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	rect.left = point.x - r;
	rect.right = point.x + r;
	rect.top = point.y - R;
	rect.bottom = point.y + R;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
