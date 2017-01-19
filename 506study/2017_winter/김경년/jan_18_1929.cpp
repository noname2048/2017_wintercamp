#include <iostream>
using namespace std;

namespace ±è°æ³â {
	int jan_18_1929() {
		int a[100000];
		int i, j, b;
		int k = 0;
		int firNum, secNum;

		cin >> firNum >> secNum;

		for (i = firNum; i <= secNum; i++) {
			for (j = 2; j < i; j++) {
				if (i % j == 0)
					break;
			}
			if (i == j) {
				a[k] = i;
				k++;
			}
		}

		for (b = 0; b < 100000; b++) {
			if (a[b] >= firNum && a[b] <= secNum && a[b] != 0) {
				cout << a[b] << endl;
			}
		}
		return 0;
	}
}