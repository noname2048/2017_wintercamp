#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
using namespace std;

namespace Á¤ÀÎ¼® {
	int 11_MATCHORDER(void) {
		freopen("11_MATCHORDER.txt", "r", stdin);

		int testcase;
		cin >> testcase;
		while (testcase--) {
			int num;
			int Russia[100], Korea[100];

			cin >> num;
			for (int i = 0; i < num; i++)
				cin >> Russia[i];

			for (int i = 0; i < num; i++)
				cin >> Korea[i];

			sort(Russia, Russia + num);
			sort(Korea, Korea + num);

			int index = 0;
			for (int i = 0; i < num; i++) {
				if (Korea[i] >= Russia[index]) {
					index++;
				}
			}

			cout << index << endl;
		}
		return 0;
	}
}
