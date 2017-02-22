#include<iostream>
using namespace std;

namespace ±è°æ³â {
	int russia[100], korea[100];
	int feb_22_MATCHORDER() {
		int testNum;
		cin >> testNum;
		while (testNum--) {
			int peopleNum, winNum = 0;
			cin >> peopleNum;
			int left = 0;

			for (int i = 0; i < peopleNum; i++)
				cin >> russia[i];
			for (int j = 0; j < peopleNum; j++)
				cin >> korea[j];
			sort(russia, peopleNum);
			sort(korea, peopleNum);
			for (int k = 0; k < peopleNum; k++) {
				if (russia[k] <= korea[left]) {
					left++;
					winNum++;
				}
			}
			cout << winNum << endl;
		}
		return 0;
	}
	void sort(int a[], int size) {
		int temp;
		for (int i = 0; i < size - 1; i++)
			for (int j = i + 1; j < size; j++)
				if (a[i] < a[j]) {
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
	}
}