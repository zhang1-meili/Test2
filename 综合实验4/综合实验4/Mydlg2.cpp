// Mydlg2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ۺ�ʵ��4.h"
#include "Mydlg2.h"
#include "afxdialogex.h"


// Mydlg2 �Ի���

IMPLEMENT_DYNAMIC(Mydlg2, CDialogEx)

Mydlg2::Mydlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, s2(_T(""))
{

}

Mydlg2::~Mydlg2()
{
}

void Mydlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s2);
}


BEGIN_MESSAGE_MAP(Mydlg2, CDialogEx)
END_MESSAGE_MAP()


// Mydlg2 ��Ϣ�������
