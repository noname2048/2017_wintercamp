#include<iostream>
using namespace std;

namespace ±è°æ³â {
	int jan_18_1978() {
		int n, i, j, k, count = 0;
		cin >> n;
		int a[100];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (j = 0; j < n; j++) {
			for (k = 2; k < a[j]; k++) {
				if (a[j] % k == 0) {
					break;
				}
			}
			if (a[j] == k)
				count++;
		}
		cout << count << endl;

		return 0;
	}
}