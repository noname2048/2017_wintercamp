#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

namespace ¡§¿ŒºÆ {
	const int MX = 10000000;

	int 7_PASS486(void) {
		static int arr[MX + 1];
		arr[0] = 0;
		arr[1] = 1;
		for (int i = 2; i <= MX; i++) {
			arr[i] = 2;
		}

		for (int i = 2; i <= MX; i++) {
			int x = 2;
			while (1) {
				if (x * i > MX) break;
				arr[x * i] += 1;
				x++;
			}
		}

		int testcase;
		scanf("%d", &testcase);

		for (int t = 0; t < testcase; t++) {
			int num, lo, hi, cnt = 0;
			scanf("%d %d %d", &num, &lo, &hi);

			for (int i = lo; i <= hi; i++) {
				if (arr[i] == num) { cnt++; }
			}
			printf("%d \n", cnt);
		}
		return 0;
	}
}

