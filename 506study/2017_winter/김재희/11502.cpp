#include<cstdio>
int temp[1001] = { 0 };

int _11502(){
	int t;
	scanf("%d", &t);
	temp[2] = 2;
	for (int i = 3; i <= 1000; i += 2)
		temp[i] = i;
	int i = 3;
	while (i*i < 1001){
		for (int j = i + 2; j <= 1000; j += 2){
			if (!temp[j]){
				continue;
			}
			if (temp[j] != i && temp[j] % i == 0) temp[j] = 0;
		}
		i += 2;
	}

	while (t--){
		int k;
		scanf("%d", &k);
		if (temp[k - 4]) {
			printf("2 2 %d\n", k - 4);
			continue;
		}
		bool check = false;
		for (int i = 3; i < k; i += 2){
			if (!temp[i]) continue;
			for (int j = 3; j < k; j += 2){
				if (!temp[j]) continue;
				for (int m = 3; m < k; m += 2){
					if (!temp[m]) continue;
					if (i + j + m == k){
						printf("%d %d %d\n", i, j, m);
						check = true;
					}
					if (i + j + m>k || check) break;
				}
				if (check) break;
			}
			if (check) break;
		}
		if (!check) printf("0\n");
	}
}
