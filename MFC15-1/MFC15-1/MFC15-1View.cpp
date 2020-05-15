
// MFC15-1View.cpp : CMFC151View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC15-1.h"
#endif

#include "MFC15-1Doc.h"
#include "MFC15-1View.h"
#include <fstream>
#include<string>
#include<iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC151View

IMPLEMENT_DYNCREATE(CMFC151View, CView)

BEGIN_MESSAGE_MAP(CMFC151View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popout, &CMFC151View::Onpopout)
END_MESSAGE_MAP()

// CMFC151View 构造/析构

CMFC151View::CMFC151View()
{
	// TODO: 在此处添加构造代码

}

CMFC151View::~CMFC151View()
{
}

BOOL CMFC151View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC151View 绘制

void CMFC151View::OnDraw(CDC* /*pDC*/)
{
	CMFC151Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC151View 打印

BOOL CMFC151View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC151View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC151View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC151View 诊断

#ifdef _DEBUG
void CMFC151View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC151View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC151Doc* CMFC151View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC151Doc)));
	return (CMFC151Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC151View 消息处理程序


void CMFC151View::Onpopout()

{

	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
    CString filename;

	if (r = IDOK)
	{
		 filename = cfd.GetPathName();
		dc.TextOutW(200, 300, filename);
		ofstream ofs("D:\\abc.txt");
		std::wstring ws(filename);
		std::string s;
		s.assign(ws.begin(), ws.end());
		ofs << s<<endl;
	}
	// TODO: 在此添加命令处理程序代码
}
