#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cmath>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
//#include<climits>
#include<cassert>
namespace ÃÖ¼º¿í {
	class RunningMedian {
	public:
		int n, a, b;
		unsigned int seed;
		RunningMedian() {
			seed = 1983;
		}
		int A() {
			int ret = seed;
			seed = (seed*(unsigned int)a + b) % 20090711;
			assert(ret < 20090711);
			assert(ret >= 0);
			return ret;
		}
		int func() {
			cin >> n >> a >> b;

			priority_queue<int> up; while (!up.empty()) up.pop();
			priority_queue<int> down; while (!down.empty()) down.pop();

			unsigned int sum = 0;
			for (int i = 0; i < n; i++) {
				if (down.size() == up.size())
					down.push(A());
				else
					up.push(-A());

				if (down.top() > (up.empty() ? 20090711 : -up.top())) {
					int tempU = -up.top(); up.pop();
					int tempD = -down.top(); down.pop();

					assert(tempU >= 0);
					assert(tempD < 0);

					down.push(tempU);
					up.push(tempD);
				}
				//assert(sum<=2448920);
				sum = (sum + (unsigned int)down.top()) % (unsigned int)20090711;
			}
			cout << sum << endl;
			return 0;
		}
	};

	int runningmedian(int input) {
		if (input) freopen("txt/runningmedian.txt", "r", stdin);

		int testCase; cin >> testCase;
		while (testCase--) {
			RunningMedian runningMedian;
			runningMedian.func();
		}
		return 0;
	}
}