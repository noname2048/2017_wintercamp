#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

void trianglepath();
int main() {
	int testcase = 0;
	scanf("%d", &testcase);

	while (testcase)
	{
		--testcase;
		trianglepath();
	}
	return 0;
}

void trianglepath() {

	int path[105][105] = { 0 };
	int result[105][105] = { 0 };
	int N, i, ret, j = 0;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		for (j = 1; j <= i; j++)
		{
			scanf("%d", path[i][j]);
		}

	result[1][1] = path[1][1];

	for (i = 2; i <= N; i++)
		for (j = 1; j <= i; j++)
		{
			result[i][j] = max(path[i][j] + result[i - 1][j], path[i][j] + result[i - 1][j - 1]);
		}

	for (i = 1; i <= N; i++)
		ret = max(ret, result[N][i]);

	printf("%d\n", ret);
}