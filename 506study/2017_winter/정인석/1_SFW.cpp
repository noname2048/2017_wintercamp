#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

namespace ¡§¿ŒºÆ{
	int 1_SFW(void) {
		int T;//testcase
		scanf("%d", &T);
		for (int i = 0; i < T; i++) {
			int N, M, r0, c0, r, c, A, B;
			//input
			scanf("%d %d %d %d %d %d %d %d",
				&N, &M, &r0, &c0, &r, &c, &A, &B);

			int k1 = abs(r0 - r);
			int k2 = abs(c0 - c);
			int result, result1, result2;

			if (k1 % A == 0) {
				result1 = k1 / A;
			}
			else { result1 = (k1 / A) + 1; }

			if (k2 % B == 0) {
				result2 = k2 / B;
			}
			else { result2 = (k2 / B) + 1; }

			result = result1 + result2;

			//output
			printf("%d \n", result);
		}

		return 0;
	}
}

