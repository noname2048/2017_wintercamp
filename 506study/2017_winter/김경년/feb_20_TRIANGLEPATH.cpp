#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

namespace ±è°æ³â {
	int tri[101][101], cache[101][101];
	int a[101];
	int triangleSum(int y, int x) {
		if (y == 1)
			return tri[1][1];
		int& ret = cache[y][x];
		if (ret != -1) return ret;
		cache[y][x] = tri[y][x] + max(triangleSum(y - 1, x - 1), triangleSum(y - 1, x));
		return cache[y][x];
	}
	int feb_20_TRIANGLEPATH() {
		int testNum;
		cin >> testNum;
		while (testNum--) {
			memset(a, -1, sizeof(a));
			memset(cache, -1, sizeof(cache));
			int lineNum;
			cin >> lineNum;
			for (int y = 1; y <= lineNum; y++)
				for (int x = 1; x <= y; x++)
					cin >> tri[y][x];
			for (int i = 1; i <= lineNum; i++)
				a[i] = triangleSum(lineNum, i);
			for (int j = 1; a[j] != -1; j++)
				if (a[0] < a[j])
					a[0] = a[j];
			cout << a[0] << endl;
		}
		return 0;
	}
}