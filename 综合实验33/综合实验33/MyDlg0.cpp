// MyDlg0.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ۺ�ʵ��33.h"
#include "MyDlg0.h"
#include "afxdialogex.h"


// MyDlg0 �Ի���

IMPLEMENT_DYNAMIC(MyDlg0, CDialogEx)

MyDlg0::MyDlg0(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, b(0)
{

}

MyDlg0::~MyDlg0()
{
}

void MyDlg0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT3, b);
}


BEGIN_MESSAGE_MAP(MyDlg0, CDialogEx)
END_MESSAGE_MAP()


// MyDlg0 ��Ϣ�������
