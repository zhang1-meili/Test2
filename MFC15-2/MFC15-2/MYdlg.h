#pragma once


// MYdlg �Ի���

class MYdlg : public CDialogEx
{
	DECLARE_DYNAMIC(MYdlg)

public:
	MYdlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MYdlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
