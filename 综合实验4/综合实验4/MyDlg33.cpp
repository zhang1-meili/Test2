// MyDlg33.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ۺ�ʵ��4.h"
#include "MyDlg33.h"
#include "afxdialogex.h"


// MyDlg33 �Ի���

IMPLEMENT_DYNAMIC(MyDlg33, CDialogEx)

MyDlg33::MyDlg33(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
//	, record(_T(""))
	, record1(_T(""))
{

}

MyDlg33::~MyDlg33()
{
}

void MyDlg33::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_LBString(pDX, IDC_LIST1, record);
	DDX_Text(pDX, IDC_EDIT2, record1);
}


BEGIN_MESSAGE_MAP(MyDlg33, CDialogEx)
END_MESSAGE_MAP()


// MyDlg33 ��Ϣ�������
