
// �ۺ�ʵ��33Set.cpp : C�ۺ�ʵ��33Set ���ʵ��
//

#include "stdafx.h"
#include "�ۺ�ʵ��33.h"
#include "�ۺ�ʵ��33Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ��33Set ʵ��

// ���������� 2020��5��19��, 17:57

IMPLEMENT_DYNAMIC(C�ۺ�ʵ��33Set, CRecordset)

C�ۺ�ʵ��33Set::C�ۺ�ʵ��33Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = 0;
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C�ۺ�ʵ��33Set::GetDefaultConnect()
{
	return _T("DSN=�ۺ�ʵ��3;DBQ=E:\\vc\\d4.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString C�ۺ�ʵ��33Set::GetDefaultSQL()
{
	return _T("[��1]");
}

void C�ۺ�ʵ��33Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// C�ۺ�ʵ��33Set ���

#ifdef _DEBUG
void C�ۺ�ʵ��33Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void C�ۺ�ʵ��33Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

