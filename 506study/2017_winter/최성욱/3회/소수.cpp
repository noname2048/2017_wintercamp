#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#include<cstring>
#include<cmath>

#include<cstdio>
#include<cstring>

#include<queue>
#include<stack>
#include<algorithm>
namespace �ּ��� {
	int �Ҽ�(int input=0) {
		freopen("txt/�Ҽ�.txt", "r", stdin);

		int n, m;
		scanf("%d %d", &n, &m);

		bool sosu[10001]; memset(sosu, true, sizeof(sosu));
		sosu[0] = sosu[1] = false;

		int now = 2;
		int sqrtN = (int)ceil(sqrt(1000000));

		//while for for ������ �Ҽ� ã��
		while (now <= min(m, sqrtN)) {
			//�Ҽ��� �ƴ� �͵��� �پ�ѱ� (now�� 2, 3, 5, 7�϶� ��������) 
			for (; now <= min(m, sqrtN) && sosu[now] == false; now++);
			//�Ҽ��� ����� �Ҽ��� �ƴ� (�������׳׽���ü)
			for (int i = 2; now * i <= min(m, 10000); i++) {
				sosu[now*i] = false;
			}
			//���� �Ҽ��� ��� �Ǿ����Ƿ� 1����
			now++;
		}

		//�Ҽ��� �ּҰ�, �Ҽ�����
		int minSoSu = -1, sumSosu = 0;
		//n���� m���� sosu[]�� ���� �Ҽ��̸� ���ϰ�, minSosu�� ����
		for (int i = n; i <= m; i++) {
			if (sosu[i]) {
				if (minSoSu == -1) minSoSu = i;
				sumSosu += i;
			}
		}

		//��� ���
		if (minSoSu == -1) cout << -1 << endl;
		else {
			cout << sumSosu << endl << minSoSu << endl;
		}
		return 0;
	}
}