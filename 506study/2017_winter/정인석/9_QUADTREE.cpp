#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string reverse(string::iterator& it);

namespace Á¤ÀÎ¼® {
	int 9_QUADTREE(void) {
		string str;
		string::iterator it;
		cin >> str;
		it = str.begin();
		cout << reverse(it) << endl;

		return 0;
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

		return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
	}
}
