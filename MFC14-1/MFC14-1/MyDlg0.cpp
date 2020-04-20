// MyDlg0.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC14-1.h"
#include "MyDlg0.h"
#include "afxdialogex.h"


// MyDlg0 对话框

IMPLEMENT_DYNAMIC(MyDlg0, CDialogEx)

MyDlg0::MyDlg0(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x(0)
	, y(0)
	, r(0)
{

}

MyDlg0::~MyDlg0()
{
}

void MyDlg0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDV_MinMaxInt(pDX, x, 0, 1000);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDV_MinMaxInt(pDX, y, 0, 500);
	DDX_Text(pDX, IDC_EDIT3, r);
}


BEGIN_MESSAGE_MAP(MyDlg0, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg0::Onsum)
	ON_BN_CLICKED(IDC_BUTTON3, &MyDlg0::Oncheng)
	ON_BN_CLICKED(IDC_BUTTON4, &MyDlg0::Onchu)
	ON_BN_CLICKED(IDC_BUTTON5, &MyDlg0::OnPingF)
	ON_BN_CLICKED(IDC_BUTTON6, &MyDlg0::OnDao)

	ON_BN_CLICKED(IDC_BUTTON2, &MyDlg0::Onjian)
END_MESSAGE_MAP()


// MyDlg0 消息处理程序





void MyDlg0::Onsum()
{
	this->UpdateData(true);
	r = x + y;
	UpdateData(false);

	// TODO: 在此添加控件通知处理程序代码
}





void MyDlg0::Oncheng()
{
	this->UpdateData(true);
	r = x * y;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void MyDlg0::Onchu()
{
	this->UpdateData(true);
	r = x/ y;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void MyDlg0::OnPingF()
{
	this->UpdateData(true);
	x = sqrt(x);
	y = sqrt(y);
	r = sqrt(r);
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void MyDlg0::OnDao()
{
	this->UpdateData(true);
	x = 1/x;
	y = 1/y;
	r = 1/r;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}





void MyDlg0::Onjian()
{
	this->UpdateData(true);
	r = x - y;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}
