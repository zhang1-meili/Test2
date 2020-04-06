
// MFC10-2View.cpp : CMFC102View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC10-2.h"
#endif

#include "MFC10-2Doc.h"
#include "MFC10-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC102View

IMPLEMENT_DYNCREATE(CMFC102View, CView)

BEGIN_MESSAGE_MAP(CMFC102View, CView)
	ON_WM_CREATE()
	ON_WM_CHAR()
	ON_WM_MBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC102View 构造/析构

CMFC102View::CMFC102View()
{
	// TODO: 在此处添加构造代码

}

CMFC102View::~CMFC102View()
{
}

BOOL CMFC102View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC102View 绘制

void CMFC102View::OnDraw(CDC* pDC)
{
	CMFC102Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC102View 诊断

#ifdef _DEBUG
void CMFC102View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC102View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC102Doc* CMFC102View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC102Doc)));
	return (CMFC102Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC102View 消息处理程序


int CMFC102View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	//创建实体光标并显示?
	CreateSolidCaret(tm.tmAveCharWidth/8, tm.tmHeight);
	ShowCaret();
	// TODO:  在此添加您专用的创建代码

	return 0;
}


void CMFC102View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC viewDC(this);
	TEXTMETRIC txtm;
	viewDC.GetTextMetrics(&txtm);
	
	if (0x0D== nChar) {
		m_strLen.Empty();
		m_point.y+=txtm.tmHeight;
		SetCaretPos(m_point);
	}
	else if (0x08== nChar) {
		COLORREF precolor = viewDC.SetTextColor(viewDC.GetBkColor());

		viewDC.TextOutW(m_point.x, m_point.y,m_strLen);
		m_strLen = m_strLen.Left(m_strLen.GetLength() - 1);
		
	}
	else {
		//字符类型转换??CString??str;?
		CString str;
		str.Format(_T("%c"), nChar);
		m_strLen+=str;
		
	}

	CSize m_size = viewDC.GetTextExtent(m_strLen);
	CPoint point;

	point.x = m_point.x + m_size.cx;
	point.y = m_point.y;

	SetCaretPos(point);

	viewDC.TextOut(m_point.x, m_point.y, m_strLen);
	
	
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFC102View::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CView::OnMButtonDown(nFlags, point);
}


void CMFC102View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCaretPos(point);
	m_point = point;
	CView::OnLButtonDown(nFlags, point);
}
