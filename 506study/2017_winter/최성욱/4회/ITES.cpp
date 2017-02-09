#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cstring>
#include<queue>
namespace �ּ��� {
	//A�� �����ϴ� �Լ� seed ���� 2^32�� ������ ���
	//unsigned int ���� �����ν� �ذ��Ͽ���
	class A {
	public:
		A() {
			seed = 1983;
		}
		unsigned int seed;
		int get() {
			int ret = seed % 10000 + 1;
			seed = (seed * 214013 + 2531011);
			return ret;
		}
	};

	int ITES(int input) {
		if (input) freopen("txt/ITES.txt", "r", stdin);

		//�׽�Ʈ ���̽��� �ش��Ѵ�
		int testCase; cin >> testCase;
		while (testCase--) {
			//���� k�� ����
			int sumIsK = 0;
			//�ܰ��ȣ
			A signal;
			//k�� �����ϴ� ���� n���� ��ȣ�� ���� ����
			int k, n; cin >> k >> n;
			//�Ź� �Է¹��� temp�� �� sum
			int temp, sum = 0;
			//STL�� ���� ������ ť(�ʱ�ȭ�� ���� �Ѵ�)
			queue<int> q; while (!q.empty()) q.pop();
			//���� n�� ���� �˻��ϴµ�
			for (int i = 0; i < n; i++) {
				temp = signal.get();
				q.push(temp); sum += temp;
				/*
				//��������� ������ k�̸�
				if (sum == k) {
					sumIsK++;
					if (q.front() == 0) {
						sumIsK++;
						sum -= q.front(); q.pop();
					}
				}
				//��������� ������ k���� ũ��
				while (sum > k) {
					sum -= q.front(); q.pop();
					if (sum == k) sumIsK++;
				}
				*/
				while (sum > k) {
					sum -= q.front(); q.pop();
				}
				if (sum == k) {
					sumIsK++;
				}

			}

			cout << sumIsK << endl;
		}
		return 0;
	}
}