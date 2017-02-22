#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> h(100001, 0);
namespace ���ϴ� {
	int solve(int left, int right) {
		if (left == right) return h[left]; //���� ������ ������ return

		int mid = (left + right) / 2; //�߰��� ����

									  //return�� ����, ���ʰ� �������� ū��
		int ret = max(solve(left, mid), solve(mid + 1, right));

		//low�� high ����
		int low = mid, high = mid + 1;
		int height = min(h[low], h[high]); //���� ����

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