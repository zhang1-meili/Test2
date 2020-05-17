
// 11周-1View.cpp : CMy11周1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "11周-1.h"
#endif
#include<string>
#include "11周-1Set.h"
#include "11周-1Doc.h"
#include "11周-1View.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11周1View

IMPLEMENT_DYNCREATE(CMy11周1View, CRecordView)

BEGIN_MESSAGE_MAP(CMy11周1View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy11周1View::OnBnClickedButton1)
	ON_COMMAND(ID_RECORD_NEXT, &CMy11周1View::OnRecordNext)
	ON_COMMAND(ID_RECORD_FIRST, &CMy11周1View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_LAST, &CMy11周1View::OnRecordLast)
	ON_COMMAND(ID_RECORD_PREV, &CMy11周1View::OnRecordPrev)
END_MESSAGE_MAP()

// CMy11周1View 构造/析构

CMy11周1View::CMy11周1View()
	: CRecordView(IDD_MY111_FORM)
	, name(_T(""))
	, ID(0)
	, age(0)
	, pic(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMy11周1View::~CMy11周1View()
{
}

void CMy11周1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_F2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_F3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_Evc1jpg);
}

BOOL CMy11周1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMy11周1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_My11周1Set;
	CRecordView::OnInitialUpdate();

}


// CMy11周1View 诊断

#ifdef _DEBUG
void CMy11周1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMy11周1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMy11周1Doc* CMy11周1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11周1Doc)));
	return (CMy11周1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy11周1View 数据库支持
CRecordset* CMy11周1View::OnGetRecordset()
{
	return m_pSet;
}



// CMy11周1View 消息处理程序


void CMy11周1View::OnBnClickedButton1()
{
	CMy11周1Doc* pDoc = GetDocument();
	GetDlgItemText(IDC_EDIT4, pDoc->s);//从指定ID号的编辑控件中读取
	CImage img;
	img.Load(pDoc->s);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int w, h, sx, sy;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio) {
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}

	//img.Load(filename);
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
	// TODO: 在此添加控件通知处理程序代码
}



void CMy11周1View::OnRecordNext()
{
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	// TODO: 在此添加命令处理程序代码
}


void CMy11周1View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
}


void CMy11周1View::OnRecordLast()
{
	m_pSet->MoveLast();
	UpdateData(false);
	// TODO: 在此添加命令处理程序代码
}


void CMy11周1View::OnRecordPrev()
{
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	// TODO: 在此添加命令处理程序代码
}
