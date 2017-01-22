#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cstring>//string.h
#include<cmath>//math.h
namespace �ּ��� {
	int �Ҽ����ϱ�(int input = 0) {
		if (input) freopen("txt/�Ҽ����ϱ�.txt", "r", stdin);

		bool sosu[1000002]; memset(sosu, true, sizeof(sosu));
		sosu[0] = sosu[1] = false;

		int m, n; cin >> m >> n;
		int sqrtN = (int)ceil(sqrt(n));
		//for if for ������ �Ҽ����ϱ�
		for (int i = 2; i <= sqrtN; i++) {
			if (sosu[i])
				for (int j = 2; i*j <= n; j++) {
					sosu[i*j] = false;
				}
		}

		for (int i = m; i <= n; i++) {
			if (sosu[i]) cout << i << endl;
		}
		return 0;
	}
}