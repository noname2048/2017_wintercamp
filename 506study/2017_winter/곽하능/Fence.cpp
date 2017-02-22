#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> h(100001, 0);
namespace 곽하능 {
	int solve(int left, int right) {
		if (left == right) return h[left]; //왼쪽 오른쪽 같으면 return

		int mid = (left + right) / 2; //중간값 결정

									  //return값 결정, 왼쪽과 오른쪽중 큰값
		int ret = max(solve(left, mid), solve(mid + 1, right));

		//low와 high 정의
		int low = mid, high = mid + 1;
		int height = min(h[low], h[high]); //높이 결정

		ret = max(ret, height * 2);

		while (left < low || high < right) {
			if (high < right && (low == left || h[low - 1] < h[high + 1])) {
				++high;
				height = min(height, h[high]);
			}
			else {
				--low;
				height = min(height, h[low]);
			}

			ret = max(ret, height * (high - low + 1));
		}

		return ret;
	}

	int main() {
		int n, t;
		scanf("%d", &t);
		while (t--) {
			scanf("%d", &n);
			for (int i = 1; i <= n; i++) {
				scanf("%d", &h[i]);
			}
			printf("%d\n", solve(0, n));
		}

	}
}