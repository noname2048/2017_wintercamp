#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cmath>
#include<cstring>
namespace �ּ��� {
	int �Ҽ�ã��(int input = 0) {
		if (input) freopen("txt/�Ҽ�ã��.txt", "r", stdin);

		bool sosu[1001];  memset(sosu, true, sizeof(sosu));
		sosu[0] = sosu[1] = false;


		int sqrtN = (int)ceil(sqrt(1000));
		//for if for ������ �Ҽ�ã��
		for (int i = 2; i <= sqrtN; i++) {
			//�Ҽ��� ����� �Ҽ��� �ƴ�
			if (sosu[i]) {
				for (int j = 2; i*j <= 1000; j++) {
					sosu[i*j] = false;
				}
			}
		}

		//input �Է¹ޱ�
		int n; cin >> n;
		int temp, result = 0;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			if (sosu[temp]) result++;
		}
		cout << result << endl;
		return 0;
	}
}