
// MFC13-2View.cpp : CMFC132View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC13-2.h"
#endif

#include "MFC13-2Doc.h"
#include "MFC13-2View.h"
#include "Mydlgo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC132View

IMPLEMENT_DYNCREATE(CMFC132View, CView)

BEGIN_MESSAGE_MAP(CMFC132View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_popout, &CMFC132View::Onpopout)
END_MESSAGE_MAP()

// CMFC132View 构造/析构

CMFC132View::CMFC132View()
{
	//filename = "";
	// TODO: 在此处添加构造代码

}

CMFC132View::~CMFC132View()
{
}

BOOL CMFC132View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC132View 绘制

void CMFC132View::OnDraw(CDC* /*pDC*/)
{
	CMFC132Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC132View 打印

BOOL CMFC132View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC132View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC132View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC132View 诊断

#ifdef _DEBUG
void CMFC132View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC132View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC132Doc* CMFC132View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC132Doc)));
	return (CMFC132Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC132View 消息处理程序


void CMFC132View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC132Doc* pDoc = GetDocument();
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	//CClientDC dc(this);
	if (r = IDOK)
	{
	pDoc-> filename = cfd.GetFileName();
     GetDC()->TextOutW(200, 300,pDoc-> filename);
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFC132View::Onpopout()
{
	CMFC132Doc* pDoc = GetDocument();
	Mydlgo dlg;
	int t = dlg.DoModal();
	this->UpdateData(true);
	dlg.s1=pDoc->filename;
	UpdateData(false);
	// TODO: 在此添加命令处理程序代码
}
