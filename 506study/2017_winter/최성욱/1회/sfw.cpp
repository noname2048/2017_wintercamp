#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

namespace �ּ��� {
	int sfw(int input = 0) {
		if (input) freopen("txt/sfw.txt", "r", stdin);
		int testCase;
		scanf("%d", &testCase);
		while (testCase--) {
			//���� �Է¹ޱ�
			int n, m, r0, c0, r, c, A, B;
			cin >> n >> m >> r0 >> c0 >> r >> c >> A >> B;

			//������-������� ���밪
			int k1 = r - r0;
			if (k1 < 0) k1 *= -1;
			//unsigned int k1 = (r > r0)?(r-r0+A-1):(r0-r+A-1);
			int k2 = c - c0;
			if (k2 < 0) k2 *= -1;
			//unsigned int k2 = (c > c0)?(c-c0+A-1):(c0-c+A-1);

			//�ִ� 40������̱� ������ unsigned int�� ���� ����, -1 �� �ڿ�
			//�������� ���� ������ ���� ���
			unsigned int result = (unsigned int)(k1 + A - 1) / A
				+ (unsigned int)(k2 + B - 1) / B;
			//unsigned int result = k1 + k2;

			//�������
			cout << result << endl;
		}

		return 0;
	}
}