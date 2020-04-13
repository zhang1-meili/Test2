
// MFC11-1View.cpp : CMFC111View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC11-1.h"
#endif

#include "MFC11-1Doc.h"
#include "MFC11-1View.h"
#include "MyDlg0.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC111View

IMPLEMENT_DYNCREATE(CMFC111View, CView)

BEGIN_MESSAGE_MAP(CMFC111View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_putout, &CMFC111View::Onputout)
END_MESSAGE_MAP()

// CMFC111View 构造/析构

CMFC111View::CMFC111View()
{
	// TODO: 在此处添加构造代码

}

CMFC111View::~CMFC111View()
{
}

BOOL CMFC111View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC111View 绘制

void CMFC111View::OnDraw(CDC* /*pDC*/)
{
	CMFC111Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC111View 打印

BOOL CMFC111View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC111View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC111View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC111View 诊断

#ifdef _DEBUG
void CMFC111View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC111View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC111Doc* CMFC111View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC111Doc)));
	return (CMFC111Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC111View 消息处理程序


void CMFC111View::Onputout()
{ 

	MyDlg0 dlg = new MyDlg0();
	int t = dlg.DoModal();
	if (t = IDOK) {
		CString s;
		CClientDC dc(this);
		s.Format(_T("你已退出对话框"));
		dc.TextOutW(200,200,s);
		
	}
	// TODO: 在此添加命令处理程序代码
}
