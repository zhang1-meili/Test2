#pragma once


// MyDlg11 �Ի���

class MyDlg11 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg11)

public:
	MyDlg11(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlg11();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString s1;
};
