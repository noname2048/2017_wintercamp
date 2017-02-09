#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
	int testcase, num = 0;
	scanf("%d", &testcase);
	while (testcase--)
	{
		int i = 0;
		int arr[100000], n = 0;
		char stack[100000];
		scanf("%s", &stack);

		while (stack[i] != '\0')
		{
			if (stack[i] == 'A')
			{
				arr[n] = 1;
				n++;
			}
			if (stack[i] == 'B')
			{
				arr[n] = 2;
				n++;
			}
			if (i != 0 && n != 1)
			{
				if (arr[n - 1] == arr[n - 2])
				{
					n = n - 2;
				}
			}
			i++;
		}
		if (n == 0)
		{
			num++;	
		}
	}
	printf("%d", num);
	return 0;
}