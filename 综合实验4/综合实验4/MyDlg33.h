#pragma once


// MyDlg33 对话框

class MyDlg33 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg33)

public:
	MyDlg33(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlg33();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//CString record;
	CString record1;
};
