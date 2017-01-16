#include<cstdio>
#include<cstring>

int _2902(){
	char temp[101];
	scanf("%s", temp);
	printf("%c", temp[0]);
	int len = strlen(temp);
	for (int i = 1; i < len; i++){
		if (temp[i] == '-') printf("%c", temp[i + 1]);
	}
}