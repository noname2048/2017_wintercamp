#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#include<cstdio>
#include<stdio.h>

namespace �ּ��� {
	int KMP�¿�KMP�ϱ�(int input = 0) {
		if (input) freopen("txt/KMP�¿�KMP�ϱ�.txt", "r", stdin);
		//�̸��� ������ ����
		string str;
		//�Է¹ޱ�
		cin >> str;

		//�߸� Ǯ�̹�. �� �ձ��� ���
		printf("%c", str[0]);
		//'-'�� ������ �� �������ڸ� ���
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '-') {
				printf("%c", str[i + 1]);
			}
		}
		return 0;
	}
}