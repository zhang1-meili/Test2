#pragma once


// Mydlgo �Ի���

class Mydlgo : public CDialogEx
{
	DECLARE_DYNAMIC(Mydlgo)

public:
	Mydlgo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Mydlgo();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int x;
	int y;
	afx_msg void OnEnChangeEdit3();
	int r;
	afx_msg void OnBnClickedButton1();
};
