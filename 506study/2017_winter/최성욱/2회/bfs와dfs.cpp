#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string.h>
#include<queue>
#include<cstdio>
#include<stdio.h>
#include<stdlib.h>

namespace 최성욱 {

	//그래프의 관계를 저장해둔 배열
	bool adj[1001][1001];
	//점개수, 선개수, 시작점
	extern int n, m;
	int s;
	//dfs방문숫서를 기록
	int dfs[1000] = { 0, };
	//bfs의 방문순서를 기록
	int bfs[1000] = { 0, };
	//점의 방문을 체크하는 변수
	int visit[1000] = { 0, };

	//시작부터 몇번째 방문인지 저장 dfs[number]
	int number = 0;
	//현재 방문하고 있는 노드의 이름
	int now = -1;

	//now에서 dfs로 탐색
	void dfsSearch(int now) {
		//현재 점을 방문하였고
		visit[now] = 1;
		//dfs 순회에 기록한다
		dfs[number++] = now;
		//여기서 다른 점으로 갈 수 있는지 찾는다(재귀)
		for (int i = 1; i <= n; i++) {
			if (visit[i] == false && adj[now][i]) {
				dfsSearch(i);
			}
		}
	}

	int bfs와dfs(int input = 0) {
		if (input) freopen("txt/dfs와bfs.txt", "r", stdin);
		//메모리 초기화
		memset(adj, false, sizeof(adj));
		//n,m,s입력받기
		scanf("%d %d %d", &n, &m, &s);
		//m개의 간선을 adj에 기록하기
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a][b] = adj[b][a] = true;
		}
		/////////
		///dfs///
		/////////
		//시작점 설정
		now = s;
		//dfs방문은 0 ~ n-1까지
		number = 0;
		dfsSearch(now);

		//" " 를 처리하기 위해 맨 첫점은 for밖에서 출력
		cout << dfs[0];
		//정답 출력
		for (int i = 1; i < n; i++) {
			cout << " " << dfs[i];
		}
		//줄바꿈
		cout << endl;

		/////////
		///bfs///
		/////////
		//큐를 생성
		queue<int> q;
		memset(visit, 0, sizeof(visit));
		now = s;
		number = 0;

		//맨처음 큐에 넣고 방문을 기록
		q.push(s);
		visit[now] = 1;
		//모든 점을 방문 할 때까지
		for (; number < n; number++) {
			//큐에 집어넣은 인자를 bfs로 순회
			now = q.front(); q.pop();
			bfs[number] = now;
			//만약 여기서 갈 수 있는 다른점이 있다면 큐에 추가
			for (int i = 1; i <= n; i++) {
				if (visit[i] == false && adj[now][i]) {
					q.push(i); //now = i;
					visit[i] = true;
				}
			}
		}//모든 점 방문

		cout << bfs[0];
		for (int i = 1; i < n; i++) {
			cout << " " << bfs[i];
		}
		cout << endl;

		return 0;
	}
}