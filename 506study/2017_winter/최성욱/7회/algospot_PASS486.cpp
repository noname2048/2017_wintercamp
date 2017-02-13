#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<algorithm>
namespace ÃÖ¼º¿í {
#define MAX_PRA 10000000
	unsigned int howMany[MAX_PRA + 1] = { 0, };
	int main() {
		for (int i = 1; i <= MAX_PRA; i++) {
			for (int j = 1; i*j <= MAX_PRA; j++) {
				howMany[i*j]++;
			}
		}

		int testCase; cin >> testCase;
		while (testCase--) {
			int n, lo, hi; cin >> n >> lo >> hi;
			int sum = 0;
			for (int i = lo; i <= hi; i++) if (howMany[i] == n) sum++;
			cout << sum << endl;
		}
		return 0;
	}
}