// Mydlg0.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCA13-3.h"
#include "Mydlg0.h"
#include "afxdialogex.h"


// Mydlg0 对话框

IMPLEMENT_DYNAMIC(Mydlg0, CDialogEx)

Mydlg0::Mydlg0(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Mydlg0::~Mydlg0()
{
}

void Mydlg0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, s1);
}


BEGIN_MESSAGE_MAP(Mydlg0, CDialogEx)
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_BUTTON1, &Mydlg0::OnBnClickedButton1)
END_MESSAGE_MAP()


// Mydlg0 消息处理程序

void Mydlg0::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
}



void Mydlg0::OnBnClickedButton1()

{
	//CString str;
	this->UpdateData(true);
	//s1.AddString(_T("使用说明.txt"));
	//s1.GetText(0,str);
	//s1.InsertString(-1,str);
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


BOOL Mydlg0::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
