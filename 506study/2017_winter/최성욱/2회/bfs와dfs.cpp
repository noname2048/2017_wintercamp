#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string.h>
#include<queue>
#include<cstdio>
#include<stdio.h>
#include<stdlib.h>

namespace �ּ��� {

	//�׷����� ���踦 �����ص� �迭
	bool adj[1001][1001];
	//������, ������, ������
	extern int n, m;
	int s;
	//dfs�湮������ ���
	int dfs[1000] = { 0, };
	//bfs�� �湮������ ���
	int bfs[1000] = { 0, };
	//���� �湮�� üũ�ϴ� ����
	int visit[1000] = { 0, };

	//���ۺ��� ���° �湮���� ���� dfs[number]
	int number = 0;
	//���� �湮�ϰ� �ִ� ����� �̸�
	int now = -1;

	//now���� dfs�� Ž��
	void dfsSearch(int now) {
		//���� ���� �湮�Ͽ���
		visit[now] = 1;
		//dfs ��ȸ�� ����Ѵ�
		dfs[number++] = now;
		//���⼭ �ٸ� ������ �� �� �ִ��� ã�´�(���)
		for (int i = 1; i <= n; i++) {
			if (visit[i] == false && adj[now][i]) {
				dfsSearch(i);
			}
		}
	}

	int bfs��dfs(int input = 0) {
		if (input) freopen("txt/dfs��bfs.txt", "r", stdin);
		//�޸� �ʱ�ȭ
		memset(adj, false, sizeof(adj));
		//n,m,s�Է¹ޱ�
		scanf("%d %d %d", &n, &m, &s);
		//m���� ������ adj�� ����ϱ�
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a][b] = adj[b][a] = true;
		}
		/////////
		///dfs///
		/////////
		//������ ����
		now = s;
		//dfs�湮�� 0 ~ n-1����
		number = 0;
		dfsSearch(now);

		//" " �� ó���ϱ� ���� �� ù���� for�ۿ��� ���
		cout << dfs[0];
		//���� ���
		for (int i = 1; i < n; i++) {
			cout << " " << dfs[i];
		}
		//�ٹٲ�
		cout << endl;

		/////////
		///bfs///
		/////////
		//ť�� ����
		queue<int> q;
		memset(visit, 0, sizeof(visit));
		now = s;
		number = 0;

		//��ó�� ť�� �ְ� �湮�� ���
		q.push(s);
		visit[now] = 1;
		//��� ���� �湮 �� ������
		for (; number < n; number++) {
			//ť�� ������� ���ڸ� bfs�� ��ȸ
			now = q.front(); q.pop();
			bfs[number] = now;
			//���� ���⼭ �� �� �ִ� �ٸ����� �ִٸ� ť�� �߰�
			for (int i = 1; i <= n; i++) {
				if (visit[i] == false && adj[now][i]) {
					q.push(i); //now = i;
					visit[i] = true;
				}
			}
		}//��� �� �湮

		cout << bfs[0];
		for (int i = 1; i < n; i++) {
			cout << " " << bfs[i];
		}
		cout << endl;

		return 0;
	}
}