// Mydlg0.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCA13-3.h"
#include "Mydlg0.h"
#include "afxdialogex.h"


// Mydlg0 �Ի���

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


// Mydlg0 ��Ϣ�������

void Mydlg0::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
}



void Mydlg0::OnBnClickedButton1()

{
	//CString str;
	this->UpdateData(true);
	//s1.AddString(_T("ʹ��˵��.txt"));
	//s1.GetText(0,str);
	//s1.InsertString(-1,str);
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL Mydlg0::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
