#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#include<stack>
#include<queue>
#include<algorithm>

namespace 최성욱 {
	int 키로거(int input) {
		if (input) freopen("txt/키로거.txt", "r", stdin);

		int testCase; cin >> testCase;
		while (testCase--) {
			string log;
			cin >> log;

			stack<int> s1;
			stack<int> s2;

			for (int i = 0; i < log.length(); i++) {
				switch (log[i])
				{
				case '<':
					if (!s1.empty()) {
						s2.push(s1.top());
						s1.pop();
					}
					break;
				case '>':
					if (!s2.empty()) {
						s1.push(s2.top());
						s2.pop();
					}
					break;
				case '-':
					if (!s1.empty()) {
						s1.pop();
					}
					break;
				default:
					s1.push(log[i]);
					break;
				}
			}
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
			while (!s2.empty()) {
				char k = s2.top();
				cout << k;
				s2.pop();
			}
			cout << endl;
		}
		return 0;
	}
}