#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cmath>
#include<cstring>
namespace 최성욱 {
	int 소수찾기(int input = 0) {
		if (input) freopen("txt/소수찾기.txt", "r", stdin);

		bool sosu[1001];  memset(sosu, true, sizeof(sosu));
		sosu[0] = sosu[1] = false;


		int sqrtN = (int)ceil(sqrt(1000));
		//for if for 형식의 소수찾기
		for (int i = 2; i <= sqrtN; i++) {
			//소수의 배수는 소수가 아님
			if (sosu[i]) {
				for (int j = 2; i*j <= 1000; j++) {
					sosu[i*j] = false;
				}
			}
		}

		//input 입력받기
		int n; cin >> n;
		int temp, result = 0;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			if (sosu[temp]) result++;
		}
		cout << result << endl;
		return 0;
	}
}