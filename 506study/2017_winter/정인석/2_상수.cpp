#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

namespace 정인석 {
	int 2_상수(void) {
		char num1[1000], num2[1000];
		scanf("%s %s", num1, num2);
		char temp1 = num1[0];
		num1[0] = num1[2];
		num1[2] = temp1;

		char temp2 = num2[0];
		num2[0] = num2[2];
		num2[2] = temp2;

		int k1 = (num1[0] - '0') * 100 + (num1[1] - '0') * 10 + (num1[2] - '0');
		int k2 = (num2[0] - '0') * 100 + (num2[1] - '0') * 10 + (num2[2] - '0');

		if (k1 > k2) { printf("%d \n", k1); }
		else { printf("%d \n", k2); }


		return 0;
	}
}
