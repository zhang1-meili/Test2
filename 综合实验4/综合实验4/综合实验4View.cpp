
// �ۺ�ʵ��4View.cpp : C�ۺ�ʵ��4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ۺ�ʵ��4.h"
#endif

#include "�ۺ�ʵ��4Set.h"
#include "�ۺ�ʵ��4Doc.h"
#include "�ۺ�ʵ��4View.h"
#include "MyDlg11.h"
#include "MyDlg1.h"
#include "Mydlg2.h"
#include "MyDlg33.h"
#include "MyDlg33.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ��4View

IMPLEMENT_DYNCREATE(C�ۺ�ʵ��4View, CRecordView)

BEGIN_MESSAGE_MAP(C�ۺ�ʵ��4View, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_Paixu, &C�ۺ�ʵ��4View::OnPaixu)
	ON_COMMAND(ID_Check, &C�ۺ�ʵ��4View::OnCheck)
	ON_COMMAND(ID_List, &C�ۺ�ʵ��4View::OnList)
	ON_BN_CLICKED(IDC_BUTTON1, &C�ۺ�ʵ��4View::OnBnClickedButton1)
END_MESSAGE_MAP()

// C�ۺ�ʵ��4View ����/����

C�ۺ�ʵ��4View::C�ۺ�ʵ��4View()
	: CRecordView(IDD_MY4_FORM)
	, name(_T(""))
	, ID(0)
	, money(0)
	, scores(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

C�ۺ�ʵ��4View::~C�ۺ�ʵ��4View()
{
}

void C�ۺ�ʵ��4View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
}
BOOL C�ۺ�ʵ��4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C�ۺ�ʵ��4View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_�ۺ�ʵ��4Set;
	CRecordView::OnInitialUpdate();

}


// C�ۺ�ʵ��4View ��ӡ

BOOL C�ۺ�ʵ��4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ۺ�ʵ��4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ۺ�ʵ��4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ۺ�ʵ��4View ���

#ifdef _DEBUG
void C�ۺ�ʵ��4View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C�ۺ�ʵ��4View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C�ۺ�ʵ��4Doc* C�ۺ�ʵ��4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ۺ�ʵ��4Doc)));
	return (C�ۺ�ʵ��4Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ۺ�ʵ��4View ���ݿ�֧��
CRecordset* C�ۺ�ʵ��4View::OnGetRecordset()
{
	return m_pSet;
}



// C�ۺ�ʵ��4View ��Ϣ�������


void C�ۺ�ʵ��4View::OnPaixu()
{
	MyDlg11 dlg1;
	int r = dlg1.DoModal();
	CString s;
	if (r == IDOK) 
		s = dlg1.s1;
		m_pSet->m_strSort = s;
		m_pSet->Requery();
		UpdateData(false);
	
	

	// TODO: �ڴ���������������
}


void C�ۺ�ʵ��4View::OnCheck()
{
	Mydlg2 dlg2;
	int r = dlg2.DoModal();
	CString s;
	if (r == IDOK) 
		s = dlg2.s2;
		m_pSet->m_strFilter = s;
		m_pSet->Requery();
		UpdateData(false);
	
	// TODO: �ڴ���������������
}


void C�ۺ�ʵ��4View::OnList()
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
		str += "\r\n";//����
	pD->record1.Append(str);
	//str = _T(" ");
	m_pSet->MoveNext();	
	}
	pD->Create(IDD_DIALOG3);
	pD->ShowWindow(1);
	UpdateData(false);
	// TODO: �ڴ���������������
}


void C�ۺ�ʵ��4View::OnBnClickedButton1()
{
	m_pSet->m_strFilter = _T("");
	m_pSet->Requery();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
