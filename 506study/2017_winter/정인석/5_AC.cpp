#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <deque>//deque라이브러리 이용
#include <algorithm>//reverse 사용
using namespace std;

namespace 정인석 {
	int 5_AC(void)
	{
		int T;
		scanf("%d", &T);

		for (int i = 0; i < T; i++)
		{
			char P[100000];//수행할 함수
			int N; //배열에 들어있는 수의 개수
			deque<int> D;//D라는 이름의 int형 요소들로 구성된 deque 선언

			scanf("%s %d", P, &N);

			int x = 0;//deque안의 요소
			while (1)
			{
				char c = getchar();// 문자 하나 단위로 받음

				if (c >= '0' && c <= '9')
					x = x * 10 + (c - '0');// *10은 자리올림

				else// 아닐 경우 현재 수를 덱에 넣음 여기서는 ,나 ]이런거
				{
					if (x > 0) D.push_back(x);
					x = 0;
					if (c == ']') break;
				}
			}


			bool error = false;// 초기에는 에러 없음
			bool rev = false;//뒤집히지 않은 상태

			for (int i = 0; P[i]; i++)
			{
				if (P[i] == 'R')// 뒤집기
				{
					if (rev == false) rev = true;
					else if (rev == true) rev = false;
				}

				else if (P[i] == 'D')// 첫 번째 원소 제거
				{

					if (D.empty() == true)// 비어있는데 제거하려 하면 에러
					{
						error = true; break;
					}

					if (rev == true) D.pop_back();
					else if (rev == false) D.pop_front();
				}
			}


			/////출력Part
			if (error == true) printf("error \n");// 에러가 발생한 경우

			else// 아닐 경우 덱의 원소를 하나하나 출력
			{
				printf("[");
				if (rev == true)
				{
					reverse(D.begin(), D.end());
				}//reverse!

				for (int i = 0; i < D.size(); i++)
				{
					printf("%d", D[i]);

					if (i < D.size() - 1)
						printf(",");
				}

				printf("] \n");
			}
		}
	}

}
