
// �ۺ�ʵ��4View.h : C�ۺ�ʵ��4View ��Ľӿ�
//

#pragma once

class C�ۺ�ʵ��4Set;

class C�ۺ�ʵ��4View : public CRecordView
{
protected: // �������л�����
	C�ۺ�ʵ��4View();
	DECLARE_DYNCREATE(C�ۺ�ʵ��4View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY4_FORM };
#endif
	C�ۺ�ʵ��4Set* m_pSet;

// ����
public:
	C�ۺ�ʵ��4Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C�ۺ�ʵ��4View();
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
	double money;
	double scores;
	afx_msg void OnPaixu();
	afx_msg void OnCheck();
	afx_msg void OnList();
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // �ۺ�ʵ��4View.cpp �еĵ��԰汾
inline C�ۺ�ʵ��4Doc* C�ۺ�ʵ��4View::GetDocument() const
   { return reinterpret_cast<C�ۺ�ʵ��4Doc*>(m_pDocument); }
#endif

