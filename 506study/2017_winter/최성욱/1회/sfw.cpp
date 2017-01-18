#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

namespace 최성욱 {
	int sfw(int input = 0) {
		if (input) freopen("txt/sfw.txt", "r", stdin);
		int testCase;
		scanf("%d", &testCase);
		while (testCase--) {
			//변수 입력받기
			int n, m, r0, c0, r, c, A, B;
			cin >> n >> m >> r0 >> c0 >> r >> c >> A >> B;

			//목적지-출발지의 절대값
			int k1 = r - r0;
			if (k1 < 0) k1 *= -1;
			//unsigned int k1 = (r > r0)?(r-r0+A-1):(r0-r+A-1);
			int k2 = c - c0;
			if (k2 < 0) k2 *= -1;
			//unsigned int k2 = (c > c0)?(c-c0+A-1):(c0-c+A-1);

			//최대 40억까지이기 때문에 unsigned int로 변수 설정, -1 한 뒤에
			//나눗셈의 몫을 가지고 정답 계산
			unsigned int result = (unsigned int)(k1 + A - 1) / A
				+ (unsigned int)(k2 + B - 1) / B;
			//unsigned int result = k1 + k2;

			//정답출력
			cout << result << endl;
		}

		return 0;
	}
}