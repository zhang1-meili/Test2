// Mydlg0.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC12-4.h"
#include "Mydlg0.h"
#include "afxdialogex.h"


// Mydlg0 �Ի���

IMPLEMENT_DYNAMIC(Mydlg0, CDialogEx)

Mydlg0::Mydlg0(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s1(_T("���"))
	, a(5)
	, s2(_T("���5"))
{

}

Mydlg0::~Mydlg0()
{
}

void Mydlg0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_LBString(pDX, IDC_LIST3, s1);
	DDX_LBIndex(pDX, IDC_LIST2, a);
	DDX_LBString(pDX, IDC_LIST1, s2);
	DDX_Control(pDX, IDC_LIST1, s4);
	DDX_Control(pDX, IDC_LIST3, s3);
	DDX_Control(pDX, IDC_LIST2, b);
}


BEGIN_MESSAGE_MAP(Mydlg0, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Mydlg0::OnBnClickedButton1)
END_MESSAGE_MAP()


// Mydlg0 ��Ϣ�������


void Mydlg0::OnBnClickedButton1()
{
	CString str,str1;
	s3.AddString(_T("���"));
	s3.GetText(0, str);
	b.AddString(_T("5"));
	b.GetText(0, str1);
	//s3.InsertString(-1, str1);
	s4.InsertString(-1, str);
	s4.InsertString(-1, str1);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
