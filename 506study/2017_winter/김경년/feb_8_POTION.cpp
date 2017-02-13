#include<iostream>
using namespace std;

namespace ±è°æ³â {
	int feb_8_POTION() {
		int testNum;
		cin >> testNum;
		for (int i = 0; i < testNum; i++) {
			int num, mul = 1;
			int rec[200], mis[200], ratio[200], ans[200];
			cin >> num;
			for (int j = 0; j < num; j++)
				cin >> rec[j];
			for (int k = 0; k < num; k++)
				cin >> mis[k];
			int gcd = arrGcd(rec, num);
			for (int l = 0; l < num; l++)
				ratio[l] = rec[l] / gcd;
			for (int m = 0; m < num; m++)
				while (mis[m] > mul*ratio[m])
					mul++;
			for (int n = 0; n < num; n++) {
				ans[n] = mul*ratio[n] - mis[n];
				cout << ans[n] << " ";
			}
			cout << endl;
		}
		return 0;
	}
	int gcd(int a, int b) {
		if (a == 1 || b == 1) return 1;
		else if (a == b) return a;
		else if (a > b) return gcd(a - b, b);
		else return gcd(a, b - a);
	}
	int arrGcd(int rec[], int num) {
		int temp = rec[0];
		for (int i = 1; i < num; i++)
			temp = gcd(temp, rec[i]);
		return temp;
	}
}
