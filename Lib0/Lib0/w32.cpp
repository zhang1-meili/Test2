#include "stdafx.h"
#include "w32.h"
int factorial(int n) {
	int sum = 1;
	for (int i = 1; i <= n; i++) {
		sum = sum*i;

	}
	return sum;
}

	
float FAC::convert(float deg) {
		
		rad = (deg*PI)/180;///����=�Ƕȡ��С�180��
		return rad;
}
