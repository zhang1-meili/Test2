#pragma once


// Mydlg2 �Ի���

class Mydlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(Mydlg2)

public:
	Mydlg2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Mydlg2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString s2;
};
