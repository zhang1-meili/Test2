
// 综合实验4View.cpp : C综合实验4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "综合实验4.h"
#endif

#include "综合实验4Set.h"
#include "综合实验4Doc.h"
#include "综合实验4View.h"
#include "MyDlg11.h"
#include "MyDlg1.h"
#include "Mydlg2.h"
#include "MyDlg33.h"
#include "MyDlg33.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合实验4View

IMPLEMENT_DYNCREATE(C综合实验4View, CRecordView)

BEGIN_MESSAGE_MAP(C综合实验4View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_Paixu, &C综合实验4View::OnPaixu)
	ON_COMMAND(ID_Check, &C综合实验4View::OnCheck)
	ON_COMMAND(ID_List, &C综合实验4View::OnList)
	ON_BN_CLICKED(IDC_BUTTON1, &C综合实验4View::OnBnClickedButton1)
END_MESSAGE_MAP()

// C综合实验4View 构造/析构

C综合实验4View::C综合实验4View()
	: CRecordView(IDD_MY4_FORM)
	, name(_T(""))
	, ID(0)
	, money(0)
	, scores(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

C综合实验4View::~C综合实验4View()
{
}

void C综合实验4View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
}
BOOL C综合实验4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C综合实验4View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_综合实验4Set;
	CRecordView::OnInitialUpdate();

}


// C综合实验4View 打印

BOOL C综合实验4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C综合实验4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C综合实验4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C综合实验4View 诊断

#ifdef _DEBUG
void C综合实验4View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C综合实验4View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C综合实验4Doc* C综合实验4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C综合实验4Doc)));
	return (C综合实验4Doc*)m_pDocument;
}
#endif //_DEBUG


// C综合实验4View 数据库支持
CRecordset* C综合实验4View::OnGetRecordset()
{
	return m_pSet;
}



// C综合实验4View 消息处理程序


void C综合实验4View::OnPaixu()
{
	MyDlg11 dlg1;
	int r = dlg1.DoModal();
	CString s;
	if (r == IDOK) 
		s = dlg1.s1;
		m_pSet->m_strSort = s;
		m_pSet->Requery();
		UpdateData(false);
	
	

	// TODO: 在此添加命令处理程序代码
}


void C综合实验4View::OnCheck()
{
	Mydlg2 dlg2;
	int r = dlg2.DoModal();
	CString s;
	if (r == IDOK) 
		s = dlg2.s2;
		m_pSet->m_strFilter = s;
		m_pSet->Requery();
		UpdateData(false);
	
	// TODO: 在此添加命令处理程序代码
}


void C综合实验4View::OnList()
{
	MyDlg33 *pD = new MyDlg33();
	UpdateData(false);
	m_pSet->MoveFirst();
	while (!m_pSet->IsEOF()) {
		CString str=_T(" ");
		CString s;
		int n = m_pSet->GetODBCFieldCount();
		for (int i = 0; i < n; i++) {
			m_pSet->GetFieldValue((short)i, s);
			str = str + " "+s;			
		}
		str += "\r\n";//换行
	pD->record1.Append(str);
	//str = _T(" ");
	m_pSet->MoveNext();	
	}
	pD->Create(IDD_DIALOG3);
	pD->ShowWindow(1);
	UpdateData(false);
	// TODO: 在此添加命令处理程序代码
}


void C综合实验4View::OnBnClickedButton1()
{
	m_pSet->m_strFilter = _T("");
	m_pSet->Requery();
	// TODO: 在此添加控件通知处理程序代码
}
