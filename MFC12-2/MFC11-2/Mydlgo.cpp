// Mydlgo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC11-2.h"
#include "Mydlgo.h"
#include "afxdialogex.h"


// Mydlgo �Ի���

IMPLEMENT_DYNAMIC(Mydlgo, CDialogEx)

Mydlgo::Mydlgo(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x(0)
	, y(0)
	, r(0)
{

}

Mydlgo::~Mydlgo()
{
}

void Mydlgo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT3, r);
}


BEGIN_MESSAGE_MAP(Mydlgo, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT3, &Mydlgo::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, &Mydlgo::OnBnClickedButton1)
END_MESSAGE_MAP()


// Mydlgo ��Ϣ�������


void Mydlgo::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Mydlgo::OnBnClickedButton1()
{
	this->UpdateData(true);
	r = x + y;
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
