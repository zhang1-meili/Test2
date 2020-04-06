
// MFC7-1View.cpp : CMFC71View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC7-1.h"
#endif

#include "MFC7-1Doc.h"
#include "MFC7-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC71View

IMPLEMENT_DYNCREATE(CMFC71View, CView)

BEGIN_MESSAGE_MAP(CMFC71View, CView)
	ON_COMMAND(ID_showYuan, &CMFC71View::Onshowyuan)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC71View 构造/析构

CMFC71View::CMFC71View()
{
	// TODO: 在此处添加构造代码
	set = false;
	a=10;
	


}

CMFC71View::~CMFC71View()
{
}

BOOL CMFC71View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC71View 绘制

void CMFC71View::OnDraw(CDC* pDC)
{
	CMFC71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	SetTimer(a, 1500, NULL);
	if (set==true) {
		int red = 0, green = 0, blue = 0;
		int width =2;
		for (int s = 0; s < 8;s++){
		int color = RGB(red, green, blue);
		CPen newPen(PS_SOLID,width,color);
		CPen *oldPen = pDC->SelectObject(&newPen);
		CRect clientRec;//构造矩形
		GetClientRect(&clientRec);//取得客户区大小
		m_pt.x = (clientRec.right - clientRec.left) / 2;
		m_pt.y = (clientRec.bottom - clientRec.top) / 2;
		pDC->Ellipse(m_pt.x - a, m_pt.y + a, m_pt.x + a, m_pt.y - a);
		pDC->SelectObject(oldPen);
		red += 32;
		green += 16;
		blue += 8;
		}
	}

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC71View 诊断

#ifdef _DEBUG
void CMFC71View::AssertValid() const
{
	CView::AssertValid();
}   

void CMFC71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC71Doc* CMFC71View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC71Doc)));
	return (CMFC71Doc*)m_pDocument;
}
#endif //_DEBUG 


// CMFC71View 消息处理程序


void CMFC71View::Onshowyuan()
{
	
	set = true;
	CClientDC dc(this);
	CRect clientRec;
	GetClientRect(&clientRec);
	m_pt.x = (clientRec.right - clientRec.left) / 2;
	m_pt.y = (clientRec.bottom - clientRec.top) / 2;
	dc.Ellipse(m_pt.x - a, m_pt.y + a, m_pt.x + a, m_pt.y - a);

	// TODO: 在此添加命令处理程序代码
}


void CMFC71View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	a += 2;
	Invalidate();
	CView::OnTimer(nIDEvent);

}
