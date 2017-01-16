#include<cstdio>

int _2908(){
	char temp1[4], temp2[4];
	int a = 0, b = 0;
	scanf("%s %s", temp1, temp2);
	for (int i = 0; i < 3; i++){
		a *= 10; b *= 10;
		a += temp1[2 - i]; b += temp2[2 - i];
		a -= '0'; b -= '0';
	}
	printf("%d", a>b ? a : b);
}