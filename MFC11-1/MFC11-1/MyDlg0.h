#pragma once
#include "stdafx.h"
//#ifndef SHARED_HANDLERS
#include "MFC11-1.h"
#include "MFC11-1Doc.h"
#include "MFC11-1View.h"
#include"MyDlg0.h"

// MyDlg0 对话框

class MyDlg0 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg0)

public:
	MyDlg0(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlg0();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#include "MyDlg0.h"
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
