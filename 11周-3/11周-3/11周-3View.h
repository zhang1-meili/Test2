
// 11周-3View.h : CMy11周3View 类的接口
//

#pragma once

class CMy11周3Set;

class CMy11周3View : public CRecordView
{
protected: // 仅从序列化创建
	CMy11周3View();
	DECLARE_DYNCREATE(CMy11周3View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY113_FORM };
#endif
	CMy11周3Set* m_pSet;
	CString ss;

// 特性
public:
	CMy11周3Doc* GetDocument() const;
	void draw_pic(CString file);

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
	virtual ~CMy11周3View();
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
	double no;
	double age;
	CString pic;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // 11周-3View.cpp 中的调试版本
inline CMy11周3Doc* CMy11周3View::GetDocument() const
   { return reinterpret_cast<CMy11周3Doc*>(m_pDocument); }
#endif

