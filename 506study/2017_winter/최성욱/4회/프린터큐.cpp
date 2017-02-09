#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cstring>
#include<queue>
namespace 최성욱 {
	int 프린터큐(int input) {
		if (input) freopen("txt/프린터큐.txt", "r", stdin);

		int testCase; cin >> testCase;
		while (testCase--) {
			int n, m; cin >> n >> m;
			int important[100];
			priority_queue<int> q; while (!q.empty()) q.pop();
			for (int i = 0; i < n; i++) {
				cin >> important[i];
				q.push(important[i]);
			}

			bool visit[100]; memset(visit, false, sizeof(visit));
			for (int i = 0, j = 0; j < n; i = (i + 1) % n) {
				if (visit[i]) continue;
				if (q.top() == important[i]) {
					q.pop();
					visit[i] = true;
					j++;
					if (i == m) {
						cout << j << endl;
						break;
					}
				}
			}
		}
		return 0;
	}
}