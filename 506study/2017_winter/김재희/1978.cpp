#include<cstdio>

bool prime(int n){
	bool check = true;
	if (n == 2 || n == 3) return 1;
	if (n == 1) return 0;
	if (n % 2 == 0) return 0;
	for (int i = 3; i < n; i += 2){
		if (0 == n%i){
			check = false;
			break;
		}
	}
	return check;
}

int _1978(){
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++){
		int temp;
		scanf("%d", &temp);
		if (prime(temp)) sum++;
	}
	printf("%d", sum);
}
