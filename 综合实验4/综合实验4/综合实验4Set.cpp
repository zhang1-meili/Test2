
// �ۺ�ʵ��4Set.cpp : C�ۺ�ʵ��4Set ���ʵ��
//

#include "stdafx.h"
#include "�ۺ�ʵ��4.h"
#include "�ۺ�ʵ��4Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ��4Set ʵ��

// ���������� 2020��5��25��, 16:06

IMPLEMENT_DYNAMIC(C�ۺ�ʵ��4Set, CRecordset)

C�ۺ�ʵ��4Set::C�ۺ�ʵ��4Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	column2 = 0.0;
	column3 = 0.0;
	column4 = 0.0;
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C�ۺ�ʵ��4Set::GetDefaultConnect()
{
	return _T("DSN=ѧ����Ϣ��4;DBQ=ѧ����Ϣ���ۺ�ʵ��4��.xls;DefaultDir=E:\\vc;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString C�ۺ�ʵ��4Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void C�ۺ�ʵ��4Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Double(pFX, _T("[ѧ��]"), column2);
	RFX_Double(pFX, _T("[��н]"), column3);
	RFX_Double(pFX, _T("[�ɼ�]"), column4);

}
/////////////////////////////////////////////////////////////////////////////
// C�ۺ�ʵ��4Set ���

#ifdef _DEBUG
void C�ۺ�ʵ��4Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void C�ۺ�ʵ��4Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

