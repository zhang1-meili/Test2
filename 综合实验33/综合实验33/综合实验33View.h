
// �ۺ�ʵ��33View.h : C�ۺ�ʵ��33View ��Ľӿ�
//

#pragma once

class C�ۺ�ʵ��33Set;

class C�ۺ�ʵ��33View : public CRecordView
{
protected: // �������л�����
	C�ۺ�ʵ��33View();
	DECLARE_DYNCREATE(C�ۺ�ʵ��33View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY33_FORM };
#endif
	C�ۺ�ʵ��33Set* m_pSet;

// ����
public:
	C�ۺ�ʵ��33Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~C�ۺ�ʵ��33View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long s;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // �ۺ�ʵ��33View.cpp �еĵ��԰汾
inline C�ۺ�ʵ��33Doc* C�ۺ�ʵ��33View::GetDocument() const
   { return reinterpret_cast<C�ۺ�ʵ��33Doc*>(m_pDocument); }
#endif

