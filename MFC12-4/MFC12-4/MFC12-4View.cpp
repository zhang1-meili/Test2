
// MFC12-4View.cpp : CMFC124View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC12-4.h"
#endif

#include "MFC12-4Doc.h"
#include "MFC12-4View.h"
#include "Mydlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC124View

IMPLEMENT_DYNCREATE(CMFC124View, CView)

BEGIN_MESSAGE_MAP(CMFC124View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popout, &CMFC124View::Onpopout)
	ON_BN_CLICKED(IDOK, &CMFC124View::OnBnClickedOk)
END_MESSAGE_MAP()

// CMFC124View 构造/析构

CMFC124View::CMFC124View()
{
	// TODO: 在此处添加构造代码

}

CMFC124View::~CMFC124View()
{
}

BOOL CMFC124View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC124View 绘制

void CMFC124View::OnDraw(CDC* /*pDC*/)
{
	CMFC124Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC124View 打印

BOOL CMFC124View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC124View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC124View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC124View 诊断

#ifdef _DEBUG
void CMFC124View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC124View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC124Doc* CMFC124View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC124Doc)));
	return (CMFC124Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC124View 消息处理程序


void CMFC124View::Onpopout()
{
	Mydlg0 dlg;
	int t = dlg.DoModal();


	// TODO: 在此添加命令处理程序代码
}


void CMFC124View::OnBnClickedOk()
{

	// TODO: 在此添加控件通知处理程序代码
}



