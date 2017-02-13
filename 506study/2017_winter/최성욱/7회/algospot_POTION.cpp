#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<algorithm>
namespace ÃÖ¼º¿í {
	int n;
	int r[1000];
	int p[1000];
	int ratio[1000];

	unsigned short getGcd(unsigned short a, unsigned int b) {
		if (a == 1 || b == 1) return 1;
		else if (a == b) return a;
		else if (a > b) return getGcd(a - b, b);
		else return getGcd(a, b - a);
	}
	int testAllGcd(int length) {
		int temp = r[0];
		for (int i = 1; i < length; i++) {
			temp = getGcd(temp, r[i]);
		}
		return temp;
	}
	int main() {
		ios::sync_with_stdio(false);
		int testCase; cin >> testCase;
		while (testCase--) {
			cin >> n;
			for (int i = 0; i < n; i++) {
				cin >> r[i];
			}
			for (int i = 0; i < n; i++) {

				cin >> p[i];
			}

			int gcd = testAllGcd(n);
			for (int i = 0; i < n; i++) {
				ratio[i] = r[i] / gcd;
			}

			int mulNum = 1;
			for (int i = 0; i < n; i++) {
				while (p[i] > ratio[i] * mulNum) mulNum++;
			}

			for (int i = 0; i < n; i++) {
				cout << mulNum * ratio[i] - p[i] << " ";
			}
			cout << endl;
		}
		return 0;
	}
}