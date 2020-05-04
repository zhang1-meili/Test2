// W32D.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "W32D.h"


// 这是导出变量的一个示例
W32D_API int nW32D=0;

// 这是导出函数的一个示例。
W32D_API int fnW32D(void)
{
    return 42;
}
int factorial1(int n) {
	int sum = 1;
	for (int i = 1; i <= n; i++) {
		sum = sum*i;

	}
	return sum;
}
float convert1(float deg) {
	float rad;
	float PI = 3.14;
	rad = (deg*PI) / 180;///弧度=角度×π÷180°
	return rad;
}
// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 W32D.h
CW32D::CW32D()
{
    return;
}
