#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string.h>
#include<queue>
#include<cstdio>
#include<stdio.h>
#include<stack>
namespace 최성욱 {

	//STL의 stack을 사용합니다
	stack<char> st;
	//단어를 저장할 임시 공간입니다
	char temp[100001];
	//좋은 단어의 총 개수를 저장합니다
	int good = 0;

	int 좋은단어(int input=0) {
		if (input) freopen("txt/좋은단어.txt", "r", stdin);
		//입력받을 단어의 개수
		int n;
		scanf("%d", &n);
		//n개의 단어만큼
		for (int i = 0; i < n; i++) {
			//임시공간 초기화
			memset(temp, 0, sizeof(temp));
			//string 한번에 입력받기
			scanf("%s", temp);

			//글자 길이동안 스택을 계산합니다
			int l = strlen(temp);
			for (int j = 0; j < l; j++) {
				//만약 스택이 존재하고, 가장 최근에 저장한게 현재와 같다면
				if (!st.empty() && st.top() == temp[j]) {
					st.pop();
				}
				else {
					st.push(temp[j]);
				}
			}
			//for문이 끝나고 스택이 남아있지 않으면 좋은 단어 입니다
			if (st.empty()) good++;
			//다른 단어를 확인하기 위해 기존 스택을 비웁니다
			while (!st.empty()) st.pop();
		}
		//최종적으로 좋은단어의 개수 출력
		cout << good << endl;
		return 0;
	}
}