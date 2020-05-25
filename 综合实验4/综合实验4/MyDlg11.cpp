// MyDlg11.cpp : 实现文件
//

#include "stdafx.h"
#include "综合实验4.h"
#include "MyDlg11.h"
#include "afxdialogex.h"


// MyDlg11 对话框

IMPLEMENT_DYNAMIC(MyDlg11, CDialogEx)

MyDlg11::MyDlg11(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s1(_T(""))
{

}

MyDlg11::~MyDlg11()
{
}

void MyDlg11::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s1);
}


BEGIN_MESSAGE_MAP(MyDlg11, CDialogEx)
END_MESSAGE_MAP()


// MyDlg11 消息处理程序
