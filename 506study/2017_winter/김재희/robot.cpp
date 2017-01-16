#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>

namespace ±Ë¿Á»Ò {
	int robot() {
		int m, n;
		scanf("%d %d", &m, &n);
		int dx[4] = { 1, 0, -1, 0 };
		int dy[4] = { 0, 1, 0, -1 };
		int ix = 0, iy = 0;
		int idx = 0;
		char temp[5];
		int d;
		for (int i = 0; i < n; i++) {
			scanf("%s %d", temp, &d);
			if (temp[0] == 'T')
				idx = (idx + 3 + 2 * (d == 0)) % 4;
			if (temp[0] == 'M') {
				ix += dx[idx] * d;
				iy += dy[idx] * d;
				if (ix < 0 || iy < 0 || ix >= m || iy >= m) {
					printf("-1");
					return 0;
				}
			}
		}
		printf("%d %d", ix, iy);
	}
}