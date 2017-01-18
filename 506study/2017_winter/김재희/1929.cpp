#include<cstdio>
int temp[1000001] = { 0 };

int _1929(){
	int a, b;
	scanf("%d %d", &a, &b);
    temp[2] = 2;
	for (int i = 3; i <= b; i += 2)
		temp[i] = i;
	int i = 3;
	while (i*i < b){
		for (int j = i + 2; j <= b; j += 2){
			if (!temp[j]){
				continue;
			}
			if (temp[j] != i && temp[j] % i == 0) temp[j] = 0;
		}
		i += 2;
	}
	for (int i = a; i <= b; i++){
		if (temp[i]) printf("%d\n", temp[i]);
	}
}
