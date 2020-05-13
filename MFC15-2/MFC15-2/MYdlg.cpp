// MYdlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC15-2.h"
#include "MYdlg.h"
#include "afxdialogex.h"
#include <fstream>
#include<string>
#include<iostream>
using namespace std;

// MYdlg 对话框

IMPLEMENT_DYNAMIC(MYdlg, CDialogEx)

MYdlg::MYdlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MYdlg::IDD, pParent)
{

}

MYdlg::~MYdlg()
{
}

void MYdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MYdlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MYdlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// MYdlg 消息处理程序


void MYdlg::OnBnClickedButton1()
{
	CString filename;
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK){
		filename = cfd.GetPathName();
		//filename = "abc.txt";
		ifstream ifs(filename);
		string s;
		CString f;
		while (ifs >> s);
		f = CString(s.c_str());
	CClientDC dc(this);
	  dc.TextOutW(20, 10, f);
		CImage img;
		img.Load(f);
		CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
		int w, h, sx, sy;
		CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
		float rect_ratio = 1.0*rect.Width() / rect.Height();
		float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
		if (rect_ratio > img_ratio) {
			h = rect.Height();
			w = img_ratio*h;
			sx = (rect.Width() - w) / 2;
			sy = 0;
		}
		else
		{
			w = rect.Width();
			h = w / img_ratio;
			sx = 0;
			sy = (rect.Height() - h) / 2;
		}

		//img.Load(filename);
		pDC->SetStretchBltMode(HALFTONE);
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);
	}
	// TODO:  在此添加控件通知处理程序代码
}
