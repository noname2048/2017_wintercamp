#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

namespace Á¤ÀÎ¼® {
	int 10_TRIANGLEPATH(void) {
		freopen("10_TRIANGLEPATH.txt", "r", stdin);
		int testcase;
		cin >> testcase;

		while (testcase--) {
			int mydata[100][100];
			int Result[100][100];

			int num;
			cin >> num;

			for (int i = 0; i < num; i++) {
				for (int j = 0; j <= i; j++) {
					cin >> mydata[i][j];
				}
			}

			Result[0][0] = mydata[0][0];
			for (int i = 1; i < num; i++) {
				for (int j = 0; j <= i; j++) {
					if (j == 0) {
						Result[i][j] = mydata[i][j] + Result[i - 1][j];
					}
					else {
						Result[i][j] = mydata[i][j] +
							max(Result[i - 1][j - 1], Result[i - 1][j]);
					}
				}
			}

			int total = 0;
			vector<int> vector;
			for (int k = 0; k < num; k++) {
				vector.push_back(Result[num - 1][k]);
			}

			sort(vector.begin(), vector.end());
			int n = vector.size();
			cout << vector[n - 1] << endl;
		}
		return 0;
	}
}