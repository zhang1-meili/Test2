// Mydlgo.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC11-2.h"
#include "Mydlgo.h"
#include "afxdialogex.h"


// Mydlgo 对话框

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


// Mydlgo 消息处理程序


void Mydlgo::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Mydlgo::OnBnClickedButton1()
{
	this->UpdateData(true);
	r = x + y;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}
