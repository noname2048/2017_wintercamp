#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	int N;				              // testcase
	char input[1000001];			  // input �� �迭
	char stack_1[1000001];            // ����1
	char stack_2[1000001];            // ����2
	int top_1, top_2;                 // ����1 �� ����2�� top
	
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);


	while (N--) 
	{
		top_1 = top_2 = -1; 
		scanf("%s", input);

		for (int i = 0; input[i]; i++) 
		{
			switch (input[i]) {
			case '<':  //������ ������� ���� ��� ����1���� �ϳ����� ����2��
				if (top_1 > -1) stack_2[++top_2] = stack_1[top_1--];
				break;
			case '>':  // ����2���� �ϳ� ���� ����1��
				if (top_2 > -1) stack_1[++top_1] = stack_2[top_2--];
				break;
			case '-': // ����1���� ��ĭ ������
				if (top_1 > -1) stack_1[top_1--] = 0;
				break;
			default:  // �Էµ� �Ϲݹ��ڵ� ����1�� ����
				stack_1[++top_1] = input[i];
				break;
			}
		}

		while (top_2 > -1) 
		
			stack_1[++top_1] = stack_2[top_2--];  //����2�� ����1�� ����
		
			stack_1[top_1 + 1] = 0;

		puts(stack_1);
	}
	return 0;
}
