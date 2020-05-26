
// 第六周实验课3View.cpp : C第六周实验课3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第六周实验课3.h"
#endif

#include "第六周实验课3Doc.h"
#include "第六周实验课3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第六周实验课3View

IMPLEMENT_DYNCREATE(C第六周实验课3View, CView)

BEGIN_MESSAGE_MAP(C第六周实验课3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// C第六周实验课3View 构造/析构

C第六周实验课3View::C第六周实验课3View()
{
	// TODO: 在此处添加构造代码
	i = 0;

}

C第六周实验课3View::~C第六周实验课3View()
{
}

BOOL C第六周实验课3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第六周实验课3View 绘制

void C第六周实验课3View::OnDraw(CDC* /*pDC*/)
{
	C第六周实验课3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	for (int i = 0; i < 6; i++) {
		dc.TextOutW(0 + 18 * i, 0, ss[i]);
	}
	for (int i = 6; i <12; i++) {
		dc.TextOutW(0 +18 * (i-6),20, ss[i]);
	}
	for (int i = 12; i <36; i++) {
		dc.TextOutW(0 + 18 * (i - 12), 40, ss[i]);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// C第六周实验课3View 打印

BOOL C第六周实验课3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第六周实验课3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第六周实验课3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第六周实验课3View 诊断

#ifdef _DEBUG
void C第六周实验课3View::AssertValid() const
{
	CView::AssertValid();
}

void C第六周实验课3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第六周实验课3Doc* C第六周实验课3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第六周实验课3Doc)));
	return (C第六周实验课3Doc*)m_pDocument;
}
#endif //_DEBUG


// C第六周实验课3View 消息处理程序


void C第六周实验课3View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ss[i] = (wchar_t)nChar;
	i++;
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}
