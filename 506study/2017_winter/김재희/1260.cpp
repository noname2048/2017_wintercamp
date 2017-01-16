#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

bool dvisit[1000] = { 0 };
bool bvisit[1000] = { 0 };
bool mat[1000][1000] = { 0 };
queue<int> bfss;

void dfs(int v){
	dvisit[v - 1] = 1;
	for (int i = 0; i <= 999; i++){
		if (mat[v - 1][i] && !dvisit[i]){
			printf("%d ", i + 1);
			dfs(i + 1);
		}
	}
}

void bfs(int v){
	bvisit[v - 1] = 1;
	bfss.push(v);
	while (bfss.size()>0){
		v = bfss.front();
		bfss.pop();
		for (int i = 0; i <= 999; i++){
			if (mat[v - 1][i] && !bvisit[i]){
				bvisit[i] = 1;
				printf("%d ", i + 1);
				bfss.push(i + 1);
			}
		}
	}
}

int _1260(){
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	int from, to;
	while (m--){
		scanf("%d %d", &from, &to);
		mat[from - 1][to - 1] = mat[to - 1][from - 1] = 1;
	}
	printf("%d ", v);
	dfs(v);
	printf("\n%d ", v);
	bfs(v);
}