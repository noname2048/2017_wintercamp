#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#include<cstring>
#include<cmath>

#include<cstdio>
#include<cstring>

#include<queue>
#include<stack>
#include<algorithm>
namespace 최성욱 {
	int 소수(int input=0) {
		freopen("txt/소수.txt", "r", stdin);

		int n, m;
		scanf("%d %d", &n, &m);

		bool sosu[10001]; memset(sosu, true, sizeof(sosu));
		sosu[0] = sosu[1] = false;

		int now = 2;
		int sqrtN = (int)ceil(sqrt(1000000));

		//while for for 형식의 소수 찾기
		while (now <= min(m, sqrtN)) {
			//소수가 아닌 것들은 뛰어넘기 (now가 2, 3, 5, 7일때 빠져나감) 
			for (; now <= min(m, sqrtN) && sosu[now] == false; now++);
			//소수의 배수는 소수가 아님 (에라스토테네스의체)
			for (int i = 2; now * i <= min(m, 10000); i++) {
				sosu[now*i] = false;
			}
			//현재 소수가 계산 되었으므로 1증가
			now++;
		}

		//소수의 최소값, 소소의합
		int minSoSu = -1, sumSosu = 0;
		//n부터 m까지 sosu[]를 살펴 소수이면 더하고, minSosu는 갱신
		for (int i = n; i <= m; i++) {
			if (sosu[i]) {
				if (minSoSu == -1) minSoSu = i;
				sumSosu += i;
			}
		}

		//결과 출력
		if (minSoSu == -1) cout << -1 << endl;
		else {
			cout << sumSosu << endl << minSoSu << endl;
		}
		return 0;
	}
}