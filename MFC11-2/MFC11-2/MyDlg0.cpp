// MyDlg0.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC11-2.h"
#include "MyDlg0.h"
#include "afxdialogex.h"


// MyDlg0 �Ի���

IMPLEMENT_DYNAMIC(MyDlg0, CDialogEx)

MyDlg0::MyDlg0(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s1(_T(""))
	, s2(_T(""))
{

}

MyDlg0::~MyDlg0()
{
}

void MyDlg0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s1);
	DDX_Text(pDX, IDC_EDIT2, s2);
}


BEGIN_MESSAGE_MAP(MyDlg0, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg0::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg0 ��Ϣ�������


void MyDlg0::OnBnClickedButton1()
{
	CString  s;
	this->UpdateData(true);
	s = s1;
	s1= s2;
	s2= s;
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
