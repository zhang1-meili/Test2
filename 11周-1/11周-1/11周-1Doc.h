
// 11��-1Doc.h : CMy11��1Doc ��Ľӿ�
//


#pragma once
#include "11��-1Set.h"


class CMy11��1Doc : public CDocument
{
protected: // �������л�����
	CMy11��1Doc();
	DECLARE_DYNCREATE(CMy11��1Doc)

// ����
public:
	CMy11��1Set m_My11��1Set;
	CString s;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMy11��1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
