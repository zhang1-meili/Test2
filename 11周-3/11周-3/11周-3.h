
// 11周-3.h : 11周-3 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMy11周3App:
// 有关此类的实现，请参阅 11周-3.cpp
//

class CMy11周3App : public CWinApp
{
public:
	CMy11周3App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy11周3App theApp;
