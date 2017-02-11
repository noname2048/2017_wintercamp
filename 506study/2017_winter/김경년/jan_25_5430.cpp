#include<iostream>
#include<string>
#include<deque>
using namespace std;

namespace ±è°æ³â {
	int jan_25_5430() {
		int testNum;
		cin >> testNum;
		while (testNum--) {
			bool rev = false;
			int num, i = 0, j = 0;
			string func, arr;
			deque<int> arrNum;
			cin >> func; cin >> num; cin >> arr;
			while (arr[i] != NULL) {
				if (arr[i] >= '0' && arr[i] <= '9') {
					if (arr[i + 1] >= '0' && arr[i + 1] <= '9') {
						if (arr[i + 2] >= '0' && arr[i + 2] <= '9') {
							arrNum.push_back((arr[i] - '0') * 100 + (arr[i + 1] - '0') * 10 + arr[i + 2] - '0');
							i += 2;
						}
						else {
							arrNum.push_back((arr[i] - '0') * 10 + (arr[i + 1] - '0'));
							i++;
						}
					}
					else {
						arrNum.push_back(arr[i] - '0');
					}
				}
				i++;
			}
			while (1) {
				if (func[j] == 'R' || func[j] == 'r') {
					if (rev == false) rev = true;
					else if (rev == true) rev = false;
					j++;
				}
				else if (func[j] == 'D' || func[j] == 'd') {
					if (arrNum.size() != 0 && rev == false) arrNum.pop_front();
					else if (arrNum.size() != 0 && rev == true) arrNum.pop_back();
					else if (arrNum.size() == 0) {
						cout << "error" << endl;
						break;
					}
					j++;
				}
				else if (func[j] == NULL) {
					cout << '[';
					for (int k = 0; k != arrNum.size(); k++) {
						if (rev == false && k != arrNum.size() - 1)
							cout << arrNum[k] << ',';
						else if (rev == false && k == arrNum.size() - 1)
							cout << arrNum[k];
						else if (rev == true && k != arrNum.size() - 1)
							cout << arrNum[arrNum.size() - k - 1] << ',';
						else if (rev == true && k == arrNum.size() - 1)
							cout << arrNum[arrNum.size() - k - 1];
					}
					cout << ']' << endl;
					break;
				}
			}
		}
		return 0;
	}
}
