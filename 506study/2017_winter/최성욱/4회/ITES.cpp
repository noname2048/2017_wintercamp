#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cstring>
#include<queue>
namespace 최성욱 {
	//A를 리턴하는 함수 seed 값은 2^32로 나누는 대신
	//unsigned int 형을 씀으로써 해결하였다
	class A {
	public:
		A() {
			seed = 1983;
		}
		unsigned int seed;
		int get() {
			int ret = seed % 10000 + 1;
			seed = (seed * 214013 + 2531011);
			return ret;
		}
	};

	int ITES(int input) {
		if (input) freopen("txt/ITES.txt", "r", stdin);

		//테스트 케이스에 해당한다
		int testCase; cin >> testCase;
		while (testCase--) {
			//합이 k인 구간
			int sumIsK = 0;
			//외계신호
			A signal;
			//k를 만족하는 것을 n개의 신호를 통해 조사
			int k, n; cin >> k >> n;
			//매번 입력받을 temp와 합 sum
			int temp, sum = 0;
			//STL을 통해 구현된 큐(초기화도 같이 한다)
			queue<int> q; while (!q.empty()) q.pop();
			//이제 n번 동안 검사하는데
			for (int i = 0; i < n; i++) {
				temp = signal.get();
				q.push(temp); sum += temp;
				/*
				//현재까지의 총합이 k이면
				if (sum == k) {
					sumIsK++;
					if (q.front() == 0) {
						sumIsK++;
						sum -= q.front(); q.pop();
					}
				}
				//현재까지의 총합이 k보다 크면
				while (sum > k) {
					sum -= q.front(); q.pop();
					if (sum == k) sumIsK++;
				}
				*/
				while (sum > k) {
					sum -= q.front(); q.pop();
				}
				if (sum == k) {
					sumIsK++;
				}

			}

			cout << sumIsK << endl;
		}
		return 0;
	}
}