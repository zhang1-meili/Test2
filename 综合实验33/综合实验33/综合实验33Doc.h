
// �ۺ�ʵ��33Doc.h : C�ۺ�ʵ��33Doc ��Ľӿ�
//


#pragma once
#include "�ۺ�ʵ��33Set.h"


class C�ۺ�ʵ��33Doc : public CDocument
{
protected: // �������л�����
	C�ۺ�ʵ��33Doc();
	DECLARE_DYNCREATE(C�ۺ�ʵ��33Doc)

// ����
public:
	C�ۺ�ʵ��33Set m_�ۺ�ʵ��33Set;

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
	virtual ~C�ۺ�ʵ��33Doc();
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
