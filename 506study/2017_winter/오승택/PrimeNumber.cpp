//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int main()
//{
//	int x, y;
//	int min = 10000;
//	int num = 0;
//	int result = 0;
//	scanf("%d", &x);
//	scanf("%d", &y);
//
//	for (int i = x; i <= y; i++)
//	{
//		result = 0;
//		for (int n = 2; n <= i; n++)
//			if (i%n == 0)
//				result++;
//		if (result == 1) 
//		{
//			num += i;
//			if (min > i)
//				min = i;
//		}
//	}
//
//	if (num == 0)
//		printf("-1");
//	else {
//		printf("%d\n", num);
//		printf("%d\n", min);
//	}
//	
//	return 0;
//}
