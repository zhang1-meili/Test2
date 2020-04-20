// Mydlgo.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC13-2.h"
#include "Mydlgo.h"
#include "afxdialogex.h"


// Mydlgo 对话框

IMPLEMENT_DYNAMIC(Mydlgo, CDialogEx)

Mydlgo::Mydlgo(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s1(_T(""))
{

}

Mydlgo::~Mydlgo()
{
}

void Mydlgo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s1);
}


BEGIN_MESSAGE_MAP(Mydlgo, CDialogEx)
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_BUTTON1, &Mydlgo::OnBnClickedButton1)
END_MESSAGE_MAP()


// Mydlgo 消息处理程序




void Mydlgo::OnBnClickedButton1()
{//
	CMainFrame pMain = (CMainFrame*)AfxGetApp()->m_pMainWnd;
   //CMFC132View pView = (CMFC132View)pMain->GetActiveView();
	//首先从对话框的按钮处理函数中获得MainFrame指针
	//CMainFrame *pMain = (CMainFrame)AfxGetApp()->m_pMainWnd;
	//CMFC132View *pView = (CMFC132View )pMain->GetActiveView();
	//CDocument * pCurrentDoc = (CFrameWnd *)m_pMainWnd->GetActiveDocument();
	//以上需要注意在对话框类中包含MainFrm.h和相应的视图类的头文件

   // CMFC132Doc* pDoc = (CMFC132Doc*)pMain->GetActiveView();
	this->UpdateData(true);
	//s1 = pDoc->filename;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}
