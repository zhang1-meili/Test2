
// 11周-3Set.cpp : CMy11周3Set 类的实现
//

#include "stdafx.h"
#include "11周-3.h"
#include "11周-3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11周3Set 实现

// 代码生成在 2020年5月17日, 15:03

IMPLEMENT_DYNAMIC(CMy11周3Set, CRecordset)

CMy11周3Set::CMy11周3Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	m_F2 = 0.0;
	m_F3 = 0.0;
	m_Evc1jpg = L"";
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMy11周3Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90-\x5b66\x751f\x4fe1\x606f\xff08\x56fe\xff09;DBQ=E:\\vc\\\x5b66\x751f\x4fe1\x606f\xff08\x56fe\xff09.xls;DefaultDir=E:\\vc;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CMy11周3Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CMy11周3Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[李四]"), column1);
	RFX_Double(pFX, _T("[F2]"), m_F2);
	RFX_Double(pFX, _T("[F3]"), m_F3);
	RFX_Text(pFX, _T("[E:/vc/1#jpg]"), m_Evc1jpg);

}
/////////////////////////////////////////////////////////////////////////////
// CMy11周3Set 诊断

#ifdef _DEBUG
void CMy11周3Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMy11周3Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

