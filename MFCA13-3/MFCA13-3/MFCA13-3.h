
// MFCA13-3.h : MFCA13-3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCA133App:
// �йش����ʵ�֣������ MFCA13-3.cpp
//

class CMFCA133App : public CWinApp
{
public:
	CMFCA133App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCA133App theApp;
