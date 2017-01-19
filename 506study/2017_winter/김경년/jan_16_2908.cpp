#include<iostream>
#include<string>
using namespace std;

namespace ±è°æ³â {
	int jan_16_2908() {
		int firstNum, secondNum;
		string first, second;
		char fir[100000], sec[100000];
		cin >> first >> second;
		firstNum = first.size();
		secondNum = second.size();

		for (int i = 0; i < firstNum; i++)
			fir[i] = first.at(i);
		for (int j = 0; j < secondNum; j++)
			sec[j] = second.at(j);

		for (int a = 0; a < firstNum; a++)
			first.at(a) = fir[(firstNum - a - 1)];
		for (int b = 0; b < secondNum; b++)
			second.at(b) = sec[(secondNum - b - 1)];

		int firChange = stoi(first, 0, 10);
		int secChange = stoi(second, 0, 10);

		if (firChange - secChange > 0)
			cout << firChange << endl;
		else if (firChange - secChange <= 0)
			cout << secChange << endl;

		return 0;
	}
}