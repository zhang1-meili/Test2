
// 11��-3View.cpp : CMy11��3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "11��-3.h"
#endif

#include "11��-3Set.h"
#include "11��-3Doc.h"
#include "11��-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11��3View

IMPLEMENT_DYNCREATE(CMy11��3View, CRecordView)

BEGIN_MESSAGE_MAP(CMy11��3View, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_FIRST, &CMy11��3View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMy11��3View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMy11��3View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMy11��3View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMy11��3View ����/����

CMy11��3View::CMy11��3View()
	: CRecordView(IDD_MY113_FORM)
	, name(_T(""))
	, no(0)
	, age(0)
	, pic(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	//path = _T("E:\\vc\\");
	ss = _T("");

}

CMy11��3View::~CMy11��3View()
{
}

void CMy11��3View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_F2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_F3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_Evc1jpg);
}

BOOL CMy11��3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMy11��3View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_My11��3Set;
	CRecordView::OnInitialUpdate();

}


// CMy11��3View ��ӡ

BOOL CMy11��3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy11��3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy11��3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy11��3View ���

#ifdef _DEBUG
void CMy11��3View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMy11��3View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMy11��3Doc* CMy11��3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11��3Doc)));
	return (CMy11��3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy11��3View ���ݿ�֧��
CRecordset* CMy11��3View::OnGetRecordset()
{
	return m_pSet;
}



// CMy11��3View ��Ϣ�������


void CMy11��3View::OnRecordFirst()
{
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename,s;
	GetDlgItemText(IDC_EDIT4, s);
	filename = s;
	draw_pic(filename);
	// TODO: �ڴ���������������
}


void CMy11��3View::OnRecordPrev()
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
	// TODO: �ڴ���������������
}


void CMy11��3View::OnRecordNext()
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
	// TODO: �ڴ���������������
}


void CMy11��3View::OnRecordLast()
{
	m_pSet->MoveLast();
	UpdateData(false);
	CRect rect;
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	InvalidateRect(&rect);
	// TODO: �ڴ���������������
}
void CMy11��3View::draw_pic(CString file) {
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

void CMy11��3View::OnPaint()
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
