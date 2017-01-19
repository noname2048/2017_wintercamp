#include<iostream>
using namespace std;

namespace ±è°æ³â {
	int jan_18_2581() {
		int i, j, k = 0, sum = 0;
		int a[100];
		int firNum, secNum;

		cin >> firNum >> secNum;

		for (i = firNum; i <= secNum; i++) {
			for (j = 2; j < i; j++) {
				if (i%j == 0)
					break;
			}
			if (i == j) {
				a[k] = i;
				sum = sum + a[k];
				k++;
			}
		}
		cout << sum << endl << a[0] << endl;

		return 0;
	}
}