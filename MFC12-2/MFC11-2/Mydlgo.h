#pragma once


// Mydlgo 对话框

class Mydlgo : public CDialogEx
{
	DECLARE_DYNAMIC(Mydlgo)

public:
	Mydlgo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Mydlgo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int x;
	int y;
	afx_msg void OnEnChangeEdit3();
	int r;
	afx_msg void OnBnClickedButton1();
};
