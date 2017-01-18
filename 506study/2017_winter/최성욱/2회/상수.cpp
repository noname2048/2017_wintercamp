#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>

namespace 최성욱 {
	int 상수(int input=0) {
		if (input) freopen("txt/상수.txt", "r", stdin);
		//변수1, 변수2(3글자)
		char a[4] = { 0, }, b[4] = { 0, };
		//변수1과 2의 인덱싱
		int c = 0, d = 0;
		//10의 지수 (1->10->100)
		int e = 1;
		//a을 입력받아서 계산
		for (int i = 0; i < 3; i++) {
			scanf("%c", &a[i]);
			c += e*(a[i] - '0');
			e *= 10;
		}
		scanf("%c", &b[0]);
		e = 1;
		for (int i = 0; i < 3; i++) {
			scanf("%c", &b[i]);
			d += e*(b[i] - '0');
			e *= 10;
		}
		//더 큰수를 출력
		if (c > d) {
			printf("%d", c);
		}
		else
			printf("%d", d);
		return 0;
	}
}