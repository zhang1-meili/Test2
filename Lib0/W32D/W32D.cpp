// W32D.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "W32D.h"


// ���ǵ���������һ��ʾ��
W32D_API int nW32D=0;

// ���ǵ���������һ��ʾ����
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
	rad = (deg*PI) / 180;///����=�Ƕȡ��С�180��
	return rad;
}
// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� W32D.h
CW32D::CW32D()
{
    return;
}
