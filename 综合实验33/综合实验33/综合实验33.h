
// �ۺ�ʵ��33.h : �ۺ�ʵ��33 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ۺ�ʵ��33App:
// �йش����ʵ�֣������ �ۺ�ʵ��33.cpp
//

class C�ۺ�ʵ��33App : public CWinApp
{
public:
	C�ۺ�ʵ��33App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ۺ�ʵ��33App theApp;
