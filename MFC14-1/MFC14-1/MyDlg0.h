#pragma once
#include "afxwin.h"


// MyDlg0 �Ի���

class MyDlg0 : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg0)

public:
	MyDlg0(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlg0();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void Onsum();
	afx_msg void Oncheng();
	afx_msg void Onchu();
	afx_msg void OnPingF();
	afx_msg void OnDao();
	double x;
	double y;
	double r;
	
	afx_msg void Onjian();
};
