
// 11��-3View.h : CMy11��3View ��Ľӿ�
//

#pragma once

class CMy11��3Set;

class CMy11��3View : public CRecordView
{
protected: // �������л�����
	CMy11��3View();
	DECLARE_DYNCREATE(CMy11��3View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY113_FORM };
#endif
	CMy11��3Set* m_pSet;
	CString ss;

// ����
public:
	CMy11��3Doc* GetDocument() const;
	void draw_pic(CString file);

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
	virtual ~CMy11��3View();
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
	double no;
	double age;
	CString pic;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // 11��-3View.cpp �еĵ��԰汾
inline CMy11��3Doc* CMy11��3View::GetDocument() const
   { return reinterpret_cast<CMy11��3Doc*>(m_pDocument); }
#endif

