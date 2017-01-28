#include<iostream>
#include<string>

using namespace std;

namespace ±è°æ³â {
	int jan_25_10866() {
		int testNum;
		cin >> testNum;
		dequePractice(testNum);
		return 0;
	}

	void dequePractice(int testNum) {
		int a[20000], number, front = 1, back = 0, alpha = 9999;
		string input;
		for (int i = 0; i < testNum; i++) {
			cin >> input;
			if (input == "push_front") {
				cin >> number;
				front--;
				a[front + alpha] = number;
			}
			else if (input == "push_back") {
				cin >> number;
				back++;
				a[back + alpha] = number;

			}
			else if (input == "pop_front") {
				if (back - front >= 0) {
					cout << a[front + alpha] << endl;
					front++;
				}
				else
					cout << "-1" << endl;
			}
			else if (input == "pop_back") {
				if (back - front >= 0) {
					cout << a[back + alpha] << endl;
					back--;
				}
				else
					cout << "-1" << endl;
			}
			else if (input == "size")
				cout << back - front + 1 << endl;
			else if (input == "empty") {
				if (back - front >= 0)
					cout << "0" << endl;
				else
					cout << "1" << endl;
			}
			else if (input == "front") {
				if (back - front >= 0)
					cout << a[front + alpha] << endl;
				else
					cout << "-1" << endl;
			}
			else if (input == "back") {
				if (back - front >= 0)
					cout << a[back + alpha] << endl;
				else
					cout << "-1" << endl;
			}
		}
	}
}