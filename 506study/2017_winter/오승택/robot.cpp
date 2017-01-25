#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main()
{   
	bool ans = true;
	int m, testcase;
	int x = 0;
	int y = 0;
	int dir = 0; 

	scanf("%d, %d", &m, &testcase);

	while (testcase--)
	{
		string MODE;
		int num;
		cin >> MODE >> num;

		if (MODE == "TURN")
		{
			if (num == 0)
			{
				dir++;
				dir = dir % 4;
			}
			else if (num == 1)
			{
				dir += 3;
				dir = dir % 4;
			}
		}

		if (MODE == "MOVE")
		{
			switch (dir)
			{
			case '0': x = x + num; break;
			case '1': y = y + num; break;
			case '2': x = x - num; break;
			case '3': x = x - num; break;
			}

		}
		if (x < 0 || x > m || y < 0 || y > m)
		{
			ans = false;
			cout << -1;
		}
	}
	cout << x << "" << y << endl;
	return 0;
}
 