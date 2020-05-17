
// 11周-3View.cpp : CMy11周3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "11周-3.h"
#endif

#include "11周-3Set.h"
#include "11周-3Doc.h"
#include "11周-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11周3View

IMPLEMENT_DYNCREATE(CMy11周3View, CRecordView)

BEGIN_MESSAGE_MAP(CMy11周3View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_FIRST, &CMy11周3View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMy11周3View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMy11周3View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMy11周3View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMy11周3View 构造/析构

CMy11周3View::CMy11周3View()
	: CRecordView(IDD_MY113_FORM)
	, name(_T(""))
	, no(0)
	, age(0)
	, pic(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	//path = _T("E:\\vc\\");
	ss = _T("");

}

CMy11周3View::~CMy11周3View()
{
}

void CMy11周3View::DoDataExchange(CDataExchange* pDX)
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

BOOL CMy11周3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMy11周3View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_My11周3Set;
	CRecordView::OnInitialUpdate();

}


// CMy11周3View 打印

BOOL CMy11周3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy11周3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy11周3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy11周3View 诊断

#ifdef _DEBUG
void CMy11周3View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMy11周3View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMy11周3Doc* CMy11周3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11周3Doc)));
	return (CMy11周3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy11周3View 数据库支持
CRecordset* CMy11周3View::OnGetRecordset()
{
	return m_pSet;
}



// CMy11周3View 消息处理程序


void CMy11周3View::OnRecordFirst()
{
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename,s;
	GetDlgItemText(IDC_EDIT4, s);
	filename = s;
	draw_pic(filename);
	// TODO: 在此添加命令处理程序代码
}


void CMy11周3View::OnRecordPrev()
{
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT4, s);
	filename = s;
	draw_pic(filename);
	CRect rect;
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	// TODO: 在此添加命令处理程序代码
}


void CMy11周3View::OnRecordNext()
{
	 m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT4, s);
	filename = s;
	draw_pic(filename);
	CRect rect;
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	// TODO: 在此添加命令处理程序代码
}


void CMy11周3View::OnRecordLast()
{
	m_pSet->MoveLast();
	UpdateData(false);
	CRect rect;
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	InvalidateRect(&rect);
	// TODO: 在此添加命令处理程序代码
}
void CMy11周3View::draw_pic(CString file) {
	CImage img;
	img.Load(file);
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
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

void CMy11周3View::OnPaint()
{
	CString s1;
	GetDlgItemText(IDC_EDIT4, s1);
	ss = s1;
	CPaintDC dc(this); // device context for painting
	CImage img;
	img.Load(ss);
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
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}
