
// DB201800Set.cpp : CDB201800Set ���ʵ��
//

#include "stdafx.h"
#include "DB201800.h"
#include "DB201800Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB201800Set ʵ��

// ���������� 2020��5��5��, 15:43

IMPLEMENT_DYNAMIC(CDB201800Set, CRecordset)

CDB201800Set::CDB201800Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0.0;
	column1 = L"";
	column2 = 0.0;
	column3 = 0.0;
	column4 = 0.0;
	m_nFields = 5;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CDB201800Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90\x2014\x5b66\x751f\x4fe1\x606f;DBQ=D:\\55\\\x5b66\x751f\x4fe1\x606f.xlsx;DefaultDir=D:\\55;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CDB201800Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CDB201800Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Double(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Double(pFX, _T("[ѧ��]"), column2);
	RFX_Double(pFX, _T("[����]"), column3);
	RFX_Double(pFX, _T("[�ֻ�����]"), column4);

}
/////////////////////////////////////////////////////////////////////////////
// CDB201800Set ���

#ifdef _DEBUG
void CDB201800Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDB201800Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

