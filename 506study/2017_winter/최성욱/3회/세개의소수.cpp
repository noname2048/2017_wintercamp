#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cstring>
#include<cmath>
#include<vector>
namespace �ּ��� {
	int �����ǼҼ�(int input = 0) {
		if (input) freopen("txt/�����ǼҼ�.txt", "r", stdin);

		bool sosu[1001]; memset(sosu, true, sizeof(sosu));
		sosu[0] = sosu[1] = false;
		//���� ������ ������ �Ҽ��� �����ؼ� �����ϱ�
		vector<int> sosuOpt; sosuOpt.clear();

		int sqrtN = (int)ceil(sqrt(1000));
		//for if for ������ �Ҽ� ã��
		for (int i = 2; i <= 1000; i++) {
			//���� �Ҽ��̸� ���Ϳ� ���� �ֽ��ϴ�
			if (sosu[i]) sosuOpt.push_back(i);
			else continue;
			//�Ҽ��� ����� �Ҽ��� �ƴմϴ�
			for (int j = 2; i*j <= 1000; j++) {
				sosu[i*j] = false;
			}
		}

		int testCase; cin >> testCase;
		while (testCase--) {
			bool find = false;
			int k; cin >> k;
			//���� ������ ���� �Ǳ� ������ ù��° ���ڰ� �����Ǹ�,
			//������ ���ڴ� ������ ���� ���ں��� Ŀ���ϹǷ�
			//������� - 1������ >= 1������ 
			//������� - (1������ +2������) >= 2������ �� ������ ��������
			//����ϸ� ������ ũ�� ���� �� �ֽ��ϴ�.

			//for���� ���ǽĿ� find�� �� ������ �Ǻ� �ϰ� ������ Ȯ���ϰ�,
			//find�� ���� �Ǹ� ��� for���� �������� ���� ���� �Ѱ��� ���ո��� 
			//����ϴ°� �����Ͻñ� �ٶ��ϴ�.

			//1�� ����
			for (int i = 0; i < sosuOpt.size() && (k - sosuOpt[i] >= sosuOpt[i]) && !find; i++) {
				//2������
				for (int j = i; j < sosuOpt.size() && (k - sosuOpt[i] - sosuOpt[j] >= sosuOpt[j] && !find); j++) {
					//3���� �Ҽ������� Ȯ���ϸ� ��
					if (sosu[k - sosuOpt[i] - sosuOpt[j]]) {
						find = true;
						cout << sosuOpt[i] << " " << sosuOpt[j] << " " << k - sosuOpt[i] - sosuOpt[j] << endl;
					}
				}
			}
			if (!find) cout << 0 << endl;
		}
		return 0;
	}
}