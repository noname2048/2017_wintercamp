#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <deque>//deque���̺귯�� �̿�
#include <algorithm>//reverse ���
using namespace std;

namespace ���μ� {
	int 5_AC(void)
	{
		int T;
		scanf("%d", &T);

		for (int i = 0; i < T; i++)
		{
			char P[100000];//������ �Լ�
			int N; //�迭�� ����ִ� ���� ����
			deque<int> D;//D��� �̸��� int�� ��ҵ�� ������ deque ����

			scanf("%s %d", P, &N);

			int x = 0;//deque���� ���
			while (1)
			{
				char c = getchar();// ���� �ϳ� ������ ����

				if (c >= '0' && c <= '9')
					x = x * 10 + (c - '0');// *10�� �ڸ��ø�

				else// �ƴ� ��� ���� ���� ���� ���� ���⼭�� ,�� ]�̷���
				{
					if (x > 0) D.push_back(x);
					x = 0;
					if (c == ']') break;
				}
			}


			bool error = false;// �ʱ⿡�� ���� ����
			bool rev = false;//�������� ���� ����

			for (int i = 0; P[i]; i++)
			{
				if (P[i] == 'R')// ������
				{
					if (rev == false) rev = true;
					else if (rev == true) rev = false;
				}

				else if (P[i] == 'D')// ù ��° ���� ����
				{

					if (D.empty() == true)// ����ִµ� �����Ϸ� �ϸ� ����
					{
						error = true; break;
					}

					if (rev == true) D.pop_back();
					else if (rev == false) D.pop_front();
				}
			}


			/////���Part
			if (error == true) printf("error \n");// ������ �߻��� ���

			else// �ƴ� ��� ���� ���Ҹ� �ϳ��ϳ� ���
			{
				printf("[");
				if (rev == true)
				{
					reverse(D.begin(), D.end());
				}//reverse!

				for (int i = 0; i < D.size(); i++)
				{
					printf("%d", D[i]);

					if (i < D.size() - 1)
						printf(",");
				}

				printf("] \n");
			}
		}
	}

}
