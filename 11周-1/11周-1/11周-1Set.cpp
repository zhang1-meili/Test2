
// 11��-1Set.cpp : CMy11��1Set ���ʵ��
//

#include "stdafx.h"
#include "11��-1.h"
#include "11��-1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11��1Set ʵ��

// ���������� 2020��5��17��, 11:09

IMPLEMENT_DYNAMIC(CMy11��1Set, CRecordset)

CMy11��1Set::CMy11��1Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	m_F2 = 0.0;
	m_F3 = 0.0;
	m_Evc1jpg = L"";
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMy11��1Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x4fe1\x606f\xff08\x56fe\xff09;DBQ=E:\\VC\\\x5b66\x751f\x4fe1\x606f\xff08\x56fe\xff09.xlsx;DefaultDir=E:\\VC;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CMy11��1Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CMy11��1Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Double(pFX, _T("[F2]"), m_F2);
	RFX_Double(pFX, _T("[F3]"), m_F3);
	RFX_Text(pFX, _T("[E:/vc/1#jpg]"), m_Evc1jpg);

}
/////////////////////////////////////////////////////////////////////////////
// CMy11��1Set ���

#ifdef _DEBUG
void CMy11��1Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMy11��1Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

