
// usingLibDll.h : usingLibDll Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CusingLibDllApp:
// �йش����ʵ�֣������ usingLibDll.cpp
//

class CusingLibDllApp : public CWinApp
{
public:
	CusingLibDllApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CusingLibDllApp theApp;
