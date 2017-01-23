#include<iostream>
#include<string>
#include<queue>
using namespace std;

namespace ±è°æ³â {
	int jan_23_10845() {
		int testNum;
		cin >> testNum;
		if (testNum >= 1 && testNum <= 10000)
			queuePractice(testNum);
		return 0;
	}
	void queuePractice(int testNum) {
		queue<int> queue;
		string a;
		for (int i = 0; i < testNum; i++) {
			int k;
			cin >> a;
			if (a == "push") {
				cin >> k;
				queue.push(k);
			}
			else if (a == "pop" && queue.size() >= 1) {
				cout << queue.front() << endl;
				queue.pop();
			}
			else if (a == "pop" && queue.size() < 1)
				cout << "-1" << endl;
			else if (a == "size")
				cout << queue.size() << endl;
			else if (a == "empty")
				cout << queue.empty() << endl;
			else if (a == "front" && queue.size() >= 1)
				cout << queue.front() << endl;
			else if (a == "front" && queue.size() < 1)
				cout << "-1" << endl;
			else if (a == "back" && queue.size() >= 1)
				cout << queue.back() << endl;
			else if (a == "back" && queue.size() < 1)
				cout << "-1" << endl;
		}
	}
}