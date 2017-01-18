#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#include<cstdio>
#include<stdio.h>

namespace 최성욱 {
	int KMP는왜KMP일까(int input = 0) {
		if (input) freopen("txt/KMP는왜KMP일까.txt", "r", stdin);
		//이름을 저장할 변수
		string str;
		//입력받기
		cin >> str;

		//야매 풀이법. 맨 앞글자 출력
		printf("%c", str[0]);
		//'-'이 나오면 그 다음글자를 출력
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '-') {
				printf("%c", str[i + 1]);
			}
		}
		return 0;
	}
}