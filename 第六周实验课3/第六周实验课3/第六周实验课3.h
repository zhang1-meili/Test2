
// ������ʵ���3.h : ������ʵ���3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C������ʵ���3App:
// �йش����ʵ�֣������ ������ʵ���3.cpp
//

class C������ʵ���3App : public CWinAppEx
{
public:
	C������ʵ���3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C������ʵ���3App theApp;
