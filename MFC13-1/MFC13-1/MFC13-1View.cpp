
// MFC13-1View.cpp : CMFC131View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC13-1.h"
#endif

#include "MFC13-1Doc.h"
#include "MFC13-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC131View

IMPLEMENT_DYNCREATE(CMFC131View, CView)

BEGIN_MESSAGE_MAP(CMFC131View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC131View 构造/析构

CMFC131View::CMFC131View()
{
	// TODO: 在此处添加构造代码

}

CMFC131View::~CMFC131View()
{
}

BOOL CMFC131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC131View 绘制

void CMFC131View::OnDraw(CDC* /*pDC*/)
{
	CMFC131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC131View 打印

BOOL CMFC131View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC131View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC131View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC131View 诊断

#ifdef _DEBUG
void CMFC131View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC131View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC131Doc* CMFC131View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC131Doc)));
	return (CMFC131Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC131View 消息处理程序


void CMFC131View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	if (r = IDOK)
	{
		CString filename = cfd.GetPathName();
		dc.TextOutW(200, 300, filename);
	}



	CView::OnLButtonDblClk(nFlags, point);
}
