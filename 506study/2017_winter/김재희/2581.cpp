#include<cstdio>
int temp[10001] = { 0 };

int _2581(){
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
	int sum = 0;
	int minv = 0;
	for (int i = a; i <= b; i++){
		if (temp[i]) {
			if (!sum) minv = temp[i];
			sum += temp[i];
		}
	}
	if (sum){
		printf("%d\n%d", sum, minv);
	}
	else{
		printf("-1");
	}
}
