#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string.h>
#include<queue>
#include<cstdio>
#include<stdio.h>
#include<stack>
namespace �ּ��� {

	//STL�� stack�� ����մϴ�
	stack<char> st;
	//�ܾ ������ �ӽ� �����Դϴ�
	char temp[100001];
	//���� �ܾ��� �� ������ �����մϴ�
	int good = 0;

	int �����ܾ�(int input=0) {
		if (input) freopen("txt/�����ܾ�.txt", "r", stdin);
		//�Է¹��� �ܾ��� ����
		int n;
		scanf("%d", &n);
		//n���� �ܾŭ
		for (int i = 0; i < n; i++) {
			//�ӽð��� �ʱ�ȭ
			memset(temp, 0, sizeof(temp));
			//string �ѹ��� �Է¹ޱ�
			scanf("%s", temp);

			//���� ���̵��� ������ ����մϴ�
			int l = strlen(temp);
			for (int j = 0; j < l; j++) {
				//���� ������ �����ϰ�, ���� �ֱٿ� �����Ѱ� ����� ���ٸ�
				if (!st.empty() && st.top() == temp[j]) {
					st.pop();
				}
				else {
					st.push(temp[j]);
				}
			}
			//for���� ������ ������ �������� ������ ���� �ܾ� �Դϴ�
			if (st.empty()) good++;
			//�ٸ� �ܾ Ȯ���ϱ� ���� ���� ������ ���ϴ�
			while (!st.empty()) st.pop();
		}
		//���������� �����ܾ��� ���� ���
		cout << good << endl;
		return 0;
	}
}