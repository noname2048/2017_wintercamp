#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

namespace 정인석 {
	int 4_스택(void)
	{
		int stack[10000];
		int top = 0;
		int Number;
		string str;

		cin >> Number;
		for (int i = 0; i < Number; i++)
		{
			cin >> str;

			if (str == "push")
			{
				int num;
				cin >> num;
				stack[++top] = num;
			}

			else if (str == "pop")
			{
				if (top == 0)
				{
					cout << -1 << endl;
				}
				else
				{
					cout << stack[top--] << endl;
				}
			}

			else if (str == "size")
				cout << top << endl;

			else if (str == "empty")
			{
				if (top == 0) cout << 1 << endl;
				else cout << 0 << endl;
			}

			else if (str == "top")
			{
				if (top == 0) cout << -1 << endl;
				else cout << stack[top] << endl;
			}

		}
	}
}
