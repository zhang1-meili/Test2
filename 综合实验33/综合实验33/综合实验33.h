
// 综合实验33.h : 综合实验33 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// C综合实验33App:
// 有关此类的实现，请参阅 综合实验33.cpp
//

class C综合实验33App : public CWinApp
{
public:
	C综合实验33App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C综合实验33App theApp;
