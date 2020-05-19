
// 第九周实验课-1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "第九周实验课-1.h"
#include "第九周实验课-1Dlg.h"
#include "afxdialogex.h"
#include <fstream>
#include<string>
#include<iostream>
#include<string.h>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// C第九周实验课1Dlg 对话框



C第九周实验课1Dlg::C第九周实验课1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY1_DIALOG, pParent)
	, s(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C第九周实验课1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list_content);
	DDX_Text(pDX, IDC_EDIT1, s);
}

BEGIN_MESSAGE_MAP(C第九周实验课1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_LBN_SELCHANGE(IDC_LIST1, &C第九周实验课1Dlg::OnLbnSelchangeList1)
	ON_LBN_SELCHANGE(IDC_LIST1, &C第九周实验课1Dlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &C第九周实验课1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &C第九周实验课1Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// C第九周实验课1Dlg 消息处理程序

BOOL C第九周实验课1Dlg::OnInitDialog()//读出文件内容并放于列表框中
{
	CDialogEx::OnInitDialog();
	CString filename =_T( "E:\\vc\\学生名单.txt");
	ifstream ifs(filename);
	string s1;
	CString f;
	while (ifs >> s1){
	f = CString(s1.c_str());
	list_content.AddString(f);
}
	UpdateData(false);
	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C第九周实验课1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C第九周实验课1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C第九周实验课1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);

}



void C第九周实验课1Dlg::OnLbnSelchangeList1()//选中放入编辑控件中
{
	// TODO: 在此添加控件通知处理程序代码
	CString strText;
	int nCurSel;
	nCurSel =list_content.GetCurSel();    // 获取当前选中列表项
	list_content.GetText(nCurSel, strText);    // 获取选中列表项的字符串
	SetDlgItemText(IDC_EDIT1, strText);

}


void C第九周实验课1Dlg::OnBnClickedButton1()//修改
{
	CString strText;
	GetDlgItemText(IDC_EDIT1, strText);
	int nCurSel;
	nCurSel = list_content.GetCurSel();
	list_content.DeleteString(nCurSel);
	list_content.InsertString(nCurSel,strText);
		//TODO: 在此添加控件通知处理程序代码
}


void C第九周实验课1Dlg::OnBnClickedOk()//确定后存回文件
{
	int num = list_content.GetCount();
	int i;
	CString filename = _T("E:\\vc\\学生名单.txt");
	ofstream of(filename);
	for (i = 0; i < num; i++)
	{
		CString s;
		list_content.GetText(i, s);
		of << CT2A(s.GetString()) << endl;
	}

	// TODO: 在此添加控件通知处理程序代码
	
	CDialogEx::OnOK();
}
