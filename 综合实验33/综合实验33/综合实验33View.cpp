
// �ۺ�ʵ��33View.cpp : C�ۺ�ʵ��33View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ۺ�ʵ��33.h"
#endif

#include "�ۺ�ʵ��33Set.h"
#include "�ۺ�ʵ��33Doc.h"
#include "�ۺ�ʵ��33View.h"
#include "Mydlg.h"
#include "MyDlg0.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ��33View

IMPLEMENT_DYNCREATE(C�ۺ�ʵ��33View, CRecordView)

BEGIN_MESSAGE_MAP(C�ۺ�ʵ��33View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON3, &C�ۺ�ʵ��33View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &C�ۺ�ʵ��33View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C�ۺ�ʵ��33View::OnBnClickedButton2)
END_MESSAGE_MAP()

// C�ۺ�ʵ��33View ����/����

C�ۺ�ʵ��33View::C�ۺ�ʵ��33View()
	: CRecordView(IDD_MY33_FORM)
	, s(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

C�ۺ�ʵ��33View::~C�ۺ�ʵ��33View()
{
}

void C�ۺ�ʵ��33View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1,m_pSet->m_1);
}

BOOL C�ۺ�ʵ��33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C�ۺ�ʵ��33View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_�ۺ�ʵ��33Set;
	CRecordView::OnInitialUpdate();

}


// C�ۺ�ʵ��33View ���

#ifdef _DEBUG
void C�ۺ�ʵ��33View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C�ۺ�ʵ��33View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C�ۺ�ʵ��33Doc* C�ۺ�ʵ��33View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ۺ�ʵ��33Doc)));
	return (C�ۺ�ʵ��33Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ۺ�ʵ��33View ���ݿ�֧��
CRecordset* C�ۺ�ʵ��33View::OnGetRecordset()
{
	return m_pSet;
}



// C�ۺ�ʵ��33View ��Ϣ�������


void C�ۺ�ʵ��33View::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void C�ۺ�ʵ��33View::OnBnClickedButton1()
{
	Mydlg adddlg;
	int r = adddlg.DoModal();
	if (r == IDOK) {
		long i = adddlg.ss;
		m_pSet->AddNew();
		m_pSet->m_1 = i;
		m_pSet->Update();//�������ݿ�
		UpdateData(false);//��ʾ�ڱ༭�ؼ���
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C�ۺ�ʵ��33View::OnBnClickedButton2()
{
	MyDlg0 changedlg;
	int r = changedlg.DoModal();
	if (r == IDOK) {
		long i = changedlg.b;
		m_pSet->Edit();
		m_pSet->m_1 = i;
		m_pSet->Update();//�������ݿ�
		UpdateData(false);//��ʾ�ڱ༭�ؼ���
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
