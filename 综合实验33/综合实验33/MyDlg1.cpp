// MyDlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "综合实验33.h"
#include "MyDlg1.h"
#include "afxdialogex.h"


// MyDlg1 对话框

IMPLEMENT_DYNAMIC(MyDlg1, CDialogEx)

MyDlg1::MyDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY33_FORM, pParent)
{

}

MyDlg1::~MyDlg1()
{
}

void MyDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDlg1, CDialogEx)
END_MESSAGE_MAP()


// MyDlg1 消息处理程序
