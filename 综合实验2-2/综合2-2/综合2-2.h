
// �ۺ�2-2.h : �ۺ�2-2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ۺ�22App:
// �йش����ʵ�֣������ �ۺ�2-2.cpp
//

class C�ۺ�22App : public CWinAppEx
{
public:
	C�ۺ�22App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ۺ�22App theApp;
