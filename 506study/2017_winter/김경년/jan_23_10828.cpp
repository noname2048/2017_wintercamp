#include<iostream>
#include<stack>
#include<string>
using namespace std;

namespace ±è°æ³â {
	int jan_23_10828() {
		int testNum;
		cin >> testNum;
		if (testNum >= 1 && testNum <= 10000)
			stackPractice(testNum);
	}
	void stackPractice(int testNum) {
		stack<int> input;
		string a;
		for (int i = 0; i < testNum; i++) {
			int k;
			cin >> a;
			if (a == "push") {
				cin >> k;
				input.push(k);
			}
			else if (a == "pop" && input.size() > 0) {
				cout << input.top() << endl;
				input.pop();
			}
			else if (a == "pop" && input.size() <= 0) {
				cout << "-1" << endl;
			}
			else if (a == "top" && input.size() > 0)
				cout << input.top() << endl;
			else if (a == "top" && input.size() <= 0)
				cout << "-1" << endl;
			else if (a == "size")
				cout << input.size() << endl;
			else if (a == "empty")
				cout << input.empty() << endl;
		}
	}
}