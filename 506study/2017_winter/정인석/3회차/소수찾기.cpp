#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

namespace 정인석 {
	int 소수찾기(void)
	{
		int tot;//숫자의 개수
		int arr[100];
		int count = 0;
		printf("number=");
		scanf("%d", &tot);
		for (int i = 0; i < tot; i++)
		{
			scanf("%d", &arr[i]);
		}


		for (int k = 0; k < tot; k++)
		{
			if (Sosoo(arr[k]) == 1)
			{
				printf("%d ", arr[k]);
				count++;
			}
		}
		printf("count = %d \n", count);
		return 0;
	}


	int Sosoo(int x)
	{
		int i;
		for (i = 2; i<x; i++)
		{
			if (x%i == 0) return 0;
		}
		if (x == 1) return 0;
		return 1;

	}
}
