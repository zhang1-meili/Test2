
// 11��-1View.h : CMy11��1View ��Ľӿ�
//

#pragma once

class CMy11��1Set;

class CMy11��1View : public CRecordView
{
protected: // �������л�����
	CMy11��1View();
	DECLARE_DYNCREATE(CMy11��1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY111_FORM };
#endif
	CMy11��1Set* m_pSet;

// ����
public:
	CMy11��1Doc* GetDocument() const;

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
	virtual ~CMy11��1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	double ID;
	double age;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordLast();
	afx_msg void OnRecordPrev();
	CString pic;
};

#ifndef _DEBUG  // 11��-1View.cpp �еĵ��԰汾
inline CMy11��1Doc* CMy11��1View::GetDocument() const
   { return reinterpret_cast<CMy11��1Doc*>(m_pDocument); }
#endif

