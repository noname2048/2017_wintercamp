#include<iostream>
using namespace std;
int clock[16];
const int INF = 987654321;
const int swtch[10][6] = {
	{ 0, 1, 2, -1 },
	{ 3, 7, 9, 11, -1 },
	{ 4, 10, 14, 15, -1 },
	{ 0, 4, 5, 6, 7, -1 },
	{ 6, 7, 8, 10, 12, -1 },
	{ 0, 2, 14, 15, -1 },
	{ 3, 14, 15, -1 },
	{ 4, 5, 7, 14, 15, -1 },
	{ 1, 2, 3, 4, 5, -1 },
	{ 3, 4, 5, 9, 13, -1 }
};

void setClock(int n)
{
	for (int i = 0; swtch[n][i] != -1; i++)
	{
		const int num = swtch[n][i];
		clock[num] += 3;

		if (clock[num] == 15)
		{
			clock[num] = 3;
		}
	}
}
int min(int a, int b) { return a>b ? b : a; }
bool isSolve()
{
	for (int i = 0; i<16; i++)
	{
		if (clock[i] != 12)
		{
			return false;
		}
	}
	return true;
}

int solve(int pos, int count)
{
	if (isSolve()) return count;
	if (pos == 10) return INF;

	int ret = INF;

	for (int i = 0; i<4; i++)
	{
		ret = min(ret, solve(pos + 1, count + i));
		setClock(pos);
	}
	return ret;
}

int main() {

	int testcase = 0;

	for (cin >> testcase; testcase > 0; testcase--)
	{

		for (int i = 0; i < 16; i++) {
			cin >> clock[i];
		}

		int res = solve(0, 0);

		cout << res;

	}

	return 0;
}