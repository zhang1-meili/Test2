
// 综合实验4View.h : C综合实验4View 类的接口
//

#pragma once

class C综合实验4Set;

class C综合实验4View : public CRecordView
{
protected: // 仅从序列化创建
	C综合实验4View();
	DECLARE_DYNCREATE(C综合实验4View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY4_FORM };
#endif
	C综合实验4Set* m_pSet;

// 特性
public:
	C综合实验4Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C综合实验4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // 综合实验4View.cpp 中的调试版本
inline C综合实验4Doc* C综合实验4View::GetDocument() const
   { return reinterpret_cast<C综合实验4Doc*>(m_pDocument); }
#endif

