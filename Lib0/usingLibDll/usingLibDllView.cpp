
// usingLibDllView.cpp : CusingLibDllView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "usingLibDll.h"
#endif

#include "usingLibDllDoc.h"
#include "usingLibDllView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "w32.h"
#include "W32D.h"

// CusingLibDllView

IMPLEMENT_DYNCREATE(CusingLibDllView, CView)

BEGIN_MESSAGE_MAP(CusingLibDllView, CView)
END_MESSAGE_MAP()

// CusingLibDllView 构造/析构

CusingLibDllView::CusingLibDllView()
{
	// TODO: 在此处添加构造代码

}

CusingLibDllView::~CusingLibDllView()
{
}

BOOL CusingLibDllView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CusingLibDllView 绘制

void CusingLibDllView::OnDraw(CDC* pDC)
{
	CusingLibDllDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	int a;
	a=factorial(5);
	s.Format(_T("%d,这是静态链接求5的阶乘"), a);
	pDC->TextOutW(200, 150,s);//动态链接
	CString ss;
	ss.Format(_T("%d，这是动态链接求5的阶乘"), factorial1(5));
	pDC->TextOutW(200, 250, ss);//动态链接
	FAC fac;
	CString s1;
    s1.Format(_T("%f，这是静态链接把角度转换为弧度"), fac.convert(30.0));
	pDC->TextOutW(200, 350, s1);//静态链接
	CString s2;
	s2.Format(_T("%f，这是动态链接把角度转换为弧度"),convert1(30.0));
	pDC->TextOutW(200, 450, s2);//动态链接
	// TODO: 在此处为本机数据添加绘制代码
}


// CusingLibDllView 诊断

#ifdef _DEBUG
void CusingLibDllView::AssertValid() const
{
	CView::AssertValid();
}

void CusingLibDllView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CusingLibDllDoc* CusingLibDllView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CusingLibDllDoc)));
	return (CusingLibDllDoc*)m_pDocument;
}
#endif //_DEBUG


// CusingLibDllView 消息处理程序
