#pragma once


// MyDlg11 对话框

class MyDlg11 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg11)

public:
	MyDlg11(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlg11();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString s1;
};
