#include<iostream>
#include<algorithm>
using namespace std;
int A[10000];

int main() {

	A[0] = 1983;

	int testcase = 0;
	for (cin >> testcase; testcase > 0; testcase--)
	{
		int n = 0;
		int a = 0;
		int b = 0;
		cin >> n >> a >> b;

		int count = 0;
		int sum = 0;
		while (count < n)
		{
			count++;

			A[count] = (A[count - 1] * a + b) % 20090711;
			make_heap(A, A + count);
			sort_heap(A, A + count);

			if (count % 2 == 1)
				sum = sum + A[(count - 1) / 2];
			else {
				if (A[count / 2 + 1] > A[count / 2])
					sum = sum + A[count / 2];
				else
					sum = sum + A[count / 2 + 1];
			}
		}

		cout << sum;
	}


	return 0;
}