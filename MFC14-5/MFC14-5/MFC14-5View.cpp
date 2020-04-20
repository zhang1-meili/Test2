
// MFC14-5View.cpp : CMFC145View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC14-5.h"
#endif

#include "MFC14-5Doc.h"
#include "MFC14-5View.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC145View

IMPLEMENT_DYNCREATE(CMFC145View, CView)

BEGIN_MESSAGE_MAP(CMFC145View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popout, &CMFC145View::Onpopout)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC145View 构造/析构

CMFC145View::CMFC145View()
{
	// TODO: 在此处添加构造代码

}

CMFC145View::~CMFC145View()
{
}

BOOL CMFC145View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC145View 绘制

void CMFC145View::OnDraw(CDC* /*pDC*/)
{
	CMFC145Doc* pDoc = GetDocument();
	CClientDC dc(this);
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect(200, 150, 300, 400);
	dc.Ellipse(&rect);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC145View 打印

BOOL CMFC145View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC145View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC145View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC145View 诊断

#ifdef _DEBUG
void CMFC145View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC145View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC145Doc* CMFC145View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC145Doc)));
	return (CMFC145Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC145View 消息处理程序


void CMFC145View::Onpopout()
{
	CRect cr;
	MyDlg0 dlg;
	CPoint point;
	int t = dlg.DoModal();
	if (t = IDOK) {
		A = dlg.x;
		G= dlg.y;
		B = dlg.z;
}
	// TODO: 在此添加命令处理程序代码
}


void CMFC145View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CBrush brush(RGB(A, G, B));
	CBrush *oldbrush;
	oldbrush = dc.SelectObject(&brush);
	dc.Ellipse(200, 150, 300, 400);
	dc.SelectObject(oldbrush);
	CView::OnLButtonDown(nFlags, point);
}
