
// 11��-3Doc.h : CMy11��3Doc ��Ľӿ�
//


#pragma once
#include "11��-3Set.h"


class CMy11��3Doc : public CDocument
{
protected: // �������л�����
	CMy11��3Doc();
	DECLARE_DYNCREATE(CMy11��3Doc)

// ����
public:
	CMy11��3Set m_My11��3Set;

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
	virtual ~CMy11��3Doc();
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
