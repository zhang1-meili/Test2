
// �ھ���ʵ���-1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ھ���ʵ���-1.h"
#include "�ھ���ʵ���-1Dlg.h"
#include "afxdialogex.h"
#include <fstream>
#include<string>
#include<iostream>
#include<string.h>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C�ھ���ʵ���1Dlg �Ի���



C�ھ���ʵ���1Dlg::C�ھ���ʵ���1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY1_DIALOG, pParent)
	, s(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�ھ���ʵ���1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list_content);
	DDX_Text(pDX, IDC_EDIT1, s);
}

BEGIN_MESSAGE_MAP(C�ھ���ʵ���1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_LBN_SELCHANGE(IDC_LIST1, &C�ھ���ʵ���1Dlg::OnLbnSelchangeList1)
	ON_LBN_SELCHANGE(IDC_LIST1, &C�ھ���ʵ���1Dlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &C�ھ���ʵ���1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &C�ھ���ʵ���1Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// C�ھ���ʵ���1Dlg ��Ϣ�������

BOOL C�ھ���ʵ���1Dlg::OnInitDialog()//�����ļ����ݲ������б����
{
	CDialogEx::OnInitDialog();
	CString filename =_T( "E:\\vc\\ѧ������.txt");
	ifstream ifs(filename);
	string s1;
	CString f;
	while (ifs >> s1){
	f = CString(s1.c_str());
	list_content.AddString(f);
}
	UpdateData(false);
	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�ھ���ʵ���1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C�ھ���ʵ���1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C�ھ���ʵ���1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);

}



void C�ھ���ʵ���1Dlg::OnLbnSelchangeList1()//ѡ�з���༭�ؼ���
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strText;
	int nCurSel;
	nCurSel =list_content.GetCurSel();    // ��ȡ��ǰѡ���б���
	list_content.GetText(nCurSel, strText);    // ��ȡѡ���б�����ַ���
	SetDlgItemText(IDC_EDIT1, strText);

}


void C�ھ���ʵ���1Dlg::OnBnClickedButton1()//�޸�
{
	CString strText;
	GetDlgItemText(IDC_EDIT1, strText);
	int nCurSel;
	nCurSel = list_content.GetCurSel();
	list_content.DeleteString(nCurSel);
	list_content.InsertString(nCurSel,strText);
		//TODO: �ڴ���ӿؼ�֪ͨ����������
}


void C�ھ���ʵ���1Dlg::OnBnClickedOk()//ȷ�������ļ�
{
	int num = list_content.GetCount();
	int i;
	CString filename = _T("E:\\vc\\ѧ������.txt");
	ofstream of(filename);
	for (i = 0; i < num; i++)
	{
		CString s;
		list_content.GetText(i, s);
		of << CT2A(s.GetString()) << endl;
	}

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CDialogEx::OnOK();
}
