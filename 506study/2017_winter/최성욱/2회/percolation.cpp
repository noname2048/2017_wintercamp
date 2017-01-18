#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cstdio>
#include<string.h>
//bfs
#include<queue>
namespace �ּ��� {
	//�־��� �簢���� ũ��
	int n, m;
	//������ �Ʒ��� �������� ��ΰ� ������ true
	bool eq = false;
	//�ӽ� ���� ����, �湮�ߴ��� Ȯ��
	char cache[1000][1000];

	//x,y ������ ������ ������ ���� ���
	int dirs[4][2] = {
		{+1,+0},
		{+0,+1},
		{-1,+0},
		{+0,-1}
	};
	//�־��� x,y��ǥ�� �簢���� ����ٸ� false ����
	bool inRegion(int x, int y) {
		if (x < 0 || x >= m || y < 0 || y >= n) return false;
		return true;
	}
	//dfs����� ��� �Լ� x,y���� dfs�� Ž��
	bool getSearch(int x, int y) {
		//���ϰ� ���� y�ϴܿ� �����Ұ�� true
		bool ret = false;
		//4���� Ȯ�ο� ����
		int newX, newY;
		//������(��������)�� ã���� ��� �� �̻� Ž������ ����
		if (eq) return true;

		//4���⿡ ���ؼ�
		for (int i = 0; i < 4; i++) {
			newX = x + dirs[i][0];
			newY = y + dirs[i][1];
			//�簢�� ���ο� �ְ� ���� �湮���� �ʾҴٸ�
			if (inRegion(newX,newY) && cache[newY][newX] == '0') {
				//1�� ����� �ϴ����� �˻��Ѵ�
				cache[newY][newX] = '1';
				//�ϴ��� ��� ���� ���� ����(�ϳ��� �ظ� ã��)
				if (newY + 1 == n) eq = true;
				//��� ������ �˻� �ǽ�
				ret = ret || getSearch(newX, newY);
			}
		}//for�� ����
		return ret;
	}

	int percolation(int input = 0) {
		if (input) freopen("txt/percolation.txt", "r", stdin);
		//���� �޸� �ʱ�ȭ, char������ '2'
		memset(cache, '2', sizeof(cache));
		//�簢���� ũ�� �ޱ�
		cin >> n >> m;
		//���پ� string���·� �Է� ����
		for (int row = 0; row < n; row++) {
			scanf("%s", &cache[row]);
		}
		//�� ù���� ���鼭 ���� dfs����
		bool result = false;
		for (int row = 0, col = 0; col < m; col++) {
			if (cache[row][col] == '0') {
				cache[row][col] = '1';
				result = (result || getSearch(col, row));
				if (result) break;
			}
		}
		//����� ���� ���
		if (result) cout << "YES" << endl;
		else cout << "NO" << endl;

		return 0;
	}

	///queue�� ����Ͽ� ã�� �Լ�(bfs) �ð��ȿ��� Ǯ �� ����
	int percolation2(int input=0) {
		if(input) freopen("percolation.txt", "r", stdin);
		int n, m;
		cin >> n >> m;
		char cache[1000][1001]; memset(cache, '1', sizeof(cache));
		for (int row = 0; row < n; row++) {
			scanf("%s", cache[row]);
		}
		//STL ť�� ����
		queue<pair<int, int> > q;
		//ù���� ���鼭
		for (int row = 0, col = 0; col < m; col++) {
			//�����ϳ��ϳ� ���� ���� bfs�� �����Ѵ�
			//�湮���� �ʾҴٸ� �湮���� ����ϰ� ť�� �߰�
			if (cache[row][col] == '0') {
				q.push(make_pair(row, col));
				cache[row][col] = '1';
				//4���⿡ ���ؼ� y,x�� ���
				int dirs[4][2] = { { -1,0 },{ 0,1 },{ 0,-1 },{ 1,0 } };
				bool upToDown = false;
				pair<int, int> temp;
				//�ش��� ã�ų� ť�� ��������
				while (!(q.empty() || upToDown)) {
					//ť�� �Ǿտ��� 4���� �˻��Ͽ� �߰�
					temp = q.front(); q.pop();
					for (int i = 0; i < 4; i++) {
						int newY = temp.first + dirs[i][0];
						int newX = temp.second + dirs[i][1];
						if (newY<0 || newY>n || newX < 0 || newX >= m) continue;
						if (cache[newY][newX] != '0') continue;
						cache[newY][newX] = '1';
						if (newY == n - 1) upToDown = true;
						q.push(make_pair(newY, newX));
					}
				}
				//ť�� ��ų� �ش��� ã���� ����� ���� ���
				if (upToDown == true) { cout << "YES" << endl; return 0; }
			}

		}//��� ������ ���캸����
		cout << "NO" << endl;
		return 0;
	}
}