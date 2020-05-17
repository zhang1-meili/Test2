
// 11周-3Doc.h : CMy11周3Doc 类的接口
//


#pragma once
#include "11周-3Set.h"


class CMy11周3Doc : public CDocument
{
protected: // 仅从序列化创建
	CMy11周3Doc();
	DECLARE_DYNCREATE(CMy11周3Doc)

// 特性
public:
	CMy11周3Set m_My11周3Set;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMy11周3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
