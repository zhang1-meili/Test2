#pragma once
#include "afxwin.h"


// Mydlg0 对话框

class Mydlg0 : public CDialogEx
{
	DECLARE_DYNAMIC(Mydlg0)

public:
	Mydlg0(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Mydlg0();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox s1;
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
