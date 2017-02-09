#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cmath>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
namespace ÃÖ¼º¿í {
	class Arctic {
	public:
		int n;
		//Point
		class Point {
		public:
			double x;
			double y;
			double operator-(Point other) {
				return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
			}
		} outDoor[100];

		//dist array
		double dist[100][100];

		//make decision
		bool decision(double d) {
			vector<bool> visited(n, false);
			visited[0] = true;
			queue<int> q;
			q.push(0);
			int seen = 0;
			while (!q.empty()) {
				int here = q.front(); q.pop();
				++seen;
				//bfs
				for (int there = 0; there < n; ++there) {
					if (!visited[there] && dist[here][there] <= d) {
						visited[there] = true;
						q.push(there);
					}
				}
			}
			return seen == n;

		}

		//optimize
		double optimize() {
			double lo = 0, hi = 1416;
			for (int i = 0; i < 100; i++) {
				double mid = (lo + hi) / 2.0;

				if (decision(mid)) {
					hi = mid;
				}
				else {
					lo = mid;
				}
			}
			return hi;
		}
	};




	int arctic(int input) {
		if (input) freopen("txt/arctic.txt", "r", stdin);

		cout << fixed;
		cout.precision(2);

		int testCase; cin >> testCase;
		while (testCase--) {
			Arctic a;
			//data input
			cin >> a.n;
			double x, y;
			for (int i = 0; i < a.n; i++) {
				cin >> x >> y;
				a.outDoor[i].x = x;
				a.outDoor[i].y = y;
			}
			//precalc
			for (int i = 0; i < a.n; i++) {
				for (int j = i; j < a.n; j++) {
					a.dist[i][j] = a.dist[j][i] = a.outDoor[i] - a.outDoor[j];
				}
			}
			//calc
			double result = a.optimize();
			cout << result << endl;
		}
		return 0;
	}
}