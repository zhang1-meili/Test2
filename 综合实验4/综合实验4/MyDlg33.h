#pragma once


// MyDlg33 �Ի���

class MyDlg33 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg33)

public:
	MyDlg33(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlg33();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	//CString record;
	CString record1;
};
