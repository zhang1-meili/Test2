// MyDlg0.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC14-2.h"
#include "MyDlg0.h"
#include "afxdialogex.h"


// MyDlg0 对话框

IMPLEMENT_DYNAMIC(MyDlg0, CDialogEx)

MyDlg0::MyDlg0(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, r1(0)
	, r2(0)
{

}

MyDlg0::~MyDlg0()
{
}

void MyDlg0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, r1);
	DDX_Text(pDX, IDC_EDIT2, r2);
}


BEGIN_MESSAGE_MAP(MyDlg0, CDialogEx)
END_MESSAGE_MAP()


// MyDlg0 消息处理程序
