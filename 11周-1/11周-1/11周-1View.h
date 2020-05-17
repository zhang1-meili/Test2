
// 11周-1View.h : CMy11周1View 类的接口
//

#pragma once

class CMy11周1Set;

class CMy11周1View : public CRecordView
{
protected: // 仅从序列化创建
	CMy11周1View();
	DECLARE_DYNCREATE(CMy11周1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY111_FORM };
#endif
	CMy11周1Set* m_pSet;

// 特性
public:
	CMy11周1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMy11周1View();
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
	double age;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordLast();
	afx_msg void OnRecordPrev();
	CString pic;
};

#ifndef _DEBUG  // 11周-1View.cpp 中的调试版本
inline CMy11周1Doc* CMy11周1View::GetDocument() const
   { return reinterpret_cast<CMy11周1Doc*>(m_pDocument); }
#endif

