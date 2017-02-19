#include<iostream>
#include<string>
using namespace std;

namespace ���� {
	int feb_15_QUADTREE() {
		int testNum;
		cin >> testNum;
		while (testNum--) {
			string test, result;
			cin >> test;
			string::iterator iter;
			iter = test.begin();
			test = reverse(iter);
			cout << test << endl;
		}
	}
	string reverse(string::iterator& it) {
		char head = *it;
		++it;
		if (head == 'b' || head == 'w')
			return string(1, head);
		string upperLeft = reverse(it);
		string upperRight = reverse(it);
		string lowerLeft = reverse(it);
		string lowerRight = reverse(it);
		// ���� ���� �Ʒ� �������� ��ġ�� �ٲ۴�.
		return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
	}
}