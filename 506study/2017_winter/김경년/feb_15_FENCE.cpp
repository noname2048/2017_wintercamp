#include<iostream>
using namespace std;

namespace ±è°æ³â {
	int input[20000];
	int feb_15_FENCE() {
		int testNum, ans;
		cin >> testNum;
		while (testNum--) {
			int num, index;
			cin >> num;
			for (int i = 0; i < num; i++)
				cin >> input[i];
			ans = maxS(0, num - 1);
			cout << ans << endl;
		}
		return 0;
	}
	int min(int a, int b) {
		if (a <= b)
			return a;
		else
			return b;
	}
	int max(int a, int b) {
		if (a >= b)
			return a;
		else
			return b;
	}
	int maxS(int left, int right) {
		if (left == right)
			return input[left];
		int mid = (left + right) / 2;
		int ret = max(maxS(left, mid), maxS(mid + 1, right));
		int lo = mid, hi = mid + 1;
		int height = min(input[lo], input[hi]);
		ret = max(ret, height * 2);
		while (left < lo || hi < right) {
			if (hi < right && (lo == left || input[lo - 1] < input[hi + 1])) {
				++hi;
				height = min(height, input[hi]);
			}
			else {
				--lo;
				height = min(height, input[lo]);
			}
			ret = max(ret, height * (hi - lo + 1));
		}
		return ret;
	}
}