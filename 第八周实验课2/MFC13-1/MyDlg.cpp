// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC13-1.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg �Ի���

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s(_T(""))
	, ss(_T(""))
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s);
	DDX_LBString(pDX, IDC_LIST1, ss);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
END_MESSAGE_MAP()


// MyDlg ��Ϣ�������
