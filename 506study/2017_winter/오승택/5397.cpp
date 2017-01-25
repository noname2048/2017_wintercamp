#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	int N;				              // testcase
	char input[1000001];			  // input 값 배열
	char stack_1[1000001];            // 스택1
	char stack_2[1000001];            // 스택2
	int top_1, top_2;                 // 스택1 과 스택2의 top
	
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);


	while (N--) 
	{
		top_1 = top_2 = -1; 
		scanf("%s", input);

		for (int i = 0; input[i]; i++) 
		{
			switch (input[i]) {
			case '<':  //스택이 비어있지 않을 경우 스택1에서 하나꺼내 스택2로
				if (top_1 > -1) stack_2[++top_2] = stack_1[top_1--];
				break;
			case '>':  // 스택2에서 하나 꺼내 스택1로
				if (top_2 > -1) stack_1[++top_1] = stack_2[top_2--];
				break;
			case '-': // 스택1에서 한칸 앞으로
				if (top_1 > -1) stack_1[top_1--] = 0;
				break;
			default:  // 입력된 일반문자들 스택1에 저장
				stack_1[++top_1] = input[i];
				break;
			}
		}

		while (top_2 > -1) 
		
			stack_1[++top_1] = stack_2[top_2--];  //스택2를 스택1에 저장
		
			stack_1[top_1 + 1] = 0;

		puts(stack_1);
	}
	return 0;
}
