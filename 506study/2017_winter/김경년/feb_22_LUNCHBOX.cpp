#include<iostream>
#include<algorithm>
using namespace std;

namespace ±è°æ³â {
	int heat[10000], eat[10000];
	int feb_22_LUNCHBOX() {
		int testNum;
		cin >> testNum;
		while (testNum--) {
			int boxNum, temp1, temp2, sum = 0, time = 0;
			cin >> boxNum;
			for (int a = 0; a < boxNum; a++)
				cin >> heat[a];
			for (int b = 0; b < boxNum; b++)
				cin >> eat[b];
			for (int c = 0; c < boxNum - 1; c++) {
				for (int d = c + 1; d < boxNum; d++) {
					if (eat[c] < eat[d]) {
						temp1 = eat[c];		temp2 = heat[c];
						eat[c] = eat[d];	heat[c] = heat[d];
						eat[d] = temp1;		heat[d] = temp2;
					}
				}
			}
			for (int e = 0; e < boxNum; e++) {
				time = time + heat[e];
				sum = max(sum, time + eat[e]);
			}
			cout << sum << endl;
		}
		return 0;
	}
}