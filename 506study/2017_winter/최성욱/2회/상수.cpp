#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>

namespace �ּ��� {
	int ���(int input=0) {
		if (input) freopen("txt/���.txt", "r", stdin);
		//����1, ����2(3����)
		char a[4] = { 0, }, b[4] = { 0, };
		//����1�� 2�� �ε���
		int c = 0, d = 0;
		//10�� ���� (1->10->100)
		int e = 1;
		//a�� �Է¹޾Ƽ� ���
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
		//�� ū���� ���
		if (c > d) {
			printf("%d", c);
		}
		else
			printf("%d", d);
		return 0;
	}
}