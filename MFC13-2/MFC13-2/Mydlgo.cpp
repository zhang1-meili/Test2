// Mydlgo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC13-2.h"
#include "Mydlgo.h"
#include "afxdialogex.h"


// Mydlgo �Ի���

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


// Mydlgo ��Ϣ�������




void Mydlgo::OnBnClickedButton1()
{//
	CMainFrame pMain = (CMainFrame*)AfxGetApp()->m_pMainWnd;
   //CMFC132View pView = (CMFC132View)pMain->GetActiveView();
	//���ȴӶԻ���İ�ť�������л��MainFrameָ��
	//CMainFrame *pMain = (CMainFrame)AfxGetApp()->m_pMainWnd;
	//CMFC132View *pView = (CMFC132View )pMain->GetActiveView();
	//CDocument * pCurrentDoc = (CFrameWnd *)m_pMainWnd->GetActiveDocument();
	//������Ҫע���ڶԻ������а���MainFrm.h����Ӧ����ͼ���ͷ�ļ�

   // CMFC132Doc* pDoc = (CMFC132Doc*)pMain->GetActiveView();
	this->UpdateData(true);
	//s1 = pDoc->filename;
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
