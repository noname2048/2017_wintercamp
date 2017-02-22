#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

namespace ±è°æ³â {
	int arr[100];
	int feb_22_STRJOIN() {
		int testNum;
		cin >> testNum;
		while (testNum--) {
			int strNum;
			cin >> strNum;
			for (int i = 0; i < strNum; i++)
				cin >> arr[i];
			cout << strSum(arr, strNum) << endl;
		}
		return 0;
	}
	int strSum(int arr[], int size) {
		int sum = 0;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < size; i++)
			pq.push(arr[i]);
		while (pq.size() > 1) {
			int min1 = pq.top();
			pq.pop();
			int min2 = pq.top();
			pq.pop();
			sum = sum + min1 + min2;
			pq.push(min1 + min2);
		}
		return sum;
	}
}