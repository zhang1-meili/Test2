
// MFC14-1View.cpp : CMFC141View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC14-1.h"
#endif

#include "MFC14-1Doc.h"
#include "MFC14-1View.h"
#include "MyDlg0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC141View

IMPLEMENT_DYNCREATE(CMFC141View, CView)

BEGIN_MESSAGE_MAP(CMFC141View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popout, &CMFC141View::Onpopout)
END_MESSAGE_MAP()

// CMFC141View 构造/析构

CMFC141View::CMFC141View()
{
	// TODO: 在此处添加构造代码

}

CMFC141View::~CMFC141View()
{
}

BOOL CMFC141View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC141View 绘制

void CMFC141View::OnDraw(CDC* /*pDC*/)
{
	CMFC141Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC141View 打印

BOOL CMFC141View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC141View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC141View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC141View 诊断

#ifdef _DEBUG
void CMFC141View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC141View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC141Doc* CMFC141View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC141Doc)));
	return (CMFC141Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC141View 消息处理程序


void CMFC141View::Onpopout()
{
	MyDlg0 dlg;
	int t = dlg.DoModal();

	// TODO: 在此添加命令处理程序代码
}
