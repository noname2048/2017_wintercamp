#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cstdio>
#include<string.h>
//bfs
#include<queue>
namespace 최성욱 {
	//주어진 사각형의 크기
	int n, m;
	//위에서 아래로 내려가는 경로가 있으면 true
	bool eq = false;
	//임시 저장 공간, 방문했는지 확인
	char cache[1000][1000];

	//x,y 순으로 방향을 지정한 방향 행렬
	int dirs[4][2] = {
		{+1,+0},
		{+0,+1},
		{-1,+0},
		{+0,-1}
	};
	//주어진 x,y좌표가 사각형을 벗어났다면 false 리턴
	bool inRegion(int x, int y) {
		if (x < 0 || x >= m || y < 0 || y >= n) return false;
		return true;
	}
	//dfs방식의 재귀 함수 x,y에서 dfs로 탐색
	bool getSearch(int x, int y) {
		//리턴값 만약 y하단에 도착할경우 true
		bool ret = false;
		//4방향 확인용 변수
		int newX, newY;
		//절대해(전역변수)를 찾았을 경우 더 이상 탐색하지 않음
		if (eq) return true;

		//4방향에 대해서
		for (int i = 0; i < 4; i++) {
			newX = x + dirs[i][0];
			newY = y + dirs[i][1];
			//사각형 내부에 있고 아직 방문하지 않았다면
			if (inRegion(newX,newY) && cache[newY][newX] == '0') {
				//1로 만들고 하단인지 검사한다
				cache[newY][newX] = '1';
				//하단일 경우 전역 변수 수정(하나의 해를 찾음)
				if (newY + 1 == n) eq = true;
				//재귀 적으로 검사 실시
				ret = ret || getSearch(newX, newY);
			}
		}//for문 종료
		return ret;
	}

	int percolation(int input = 0) {
		if (input) freopen("txt/percolation.txt", "r", stdin);
		//먼저 메모리 초기화, char값으로 '2'
		memset(cache, '2', sizeof(cache));
		//사각형의 크기 받기
		cin >> n >> m;
		//한줄씩 string형태로 입력 받음
		for (int row = 0; row < n; row++) {
			scanf("%s", &cache[row]);
		}
		//맨 첫줄을 돌면서 최초 dfs실행
		bool result = false;
		for (int row = 0, col = 0; col < m; col++) {
			if (cache[row][col] == '0') {
				cache[row][col] = '1';
				result = (result || getSearch(col, row));
				if (result) break;
			}
		}
		//결과에 따른 출력
		if (result) cout << "YES" << endl;
		else cout << "NO" << endl;

		return 0;
	}

	///queue을 사용하여 찾는 함수(bfs) 시간안에는 풀 수 있음
	int percolation2(int input=0) {
		if(input) freopen("percolation.txt", "r", stdin);
		int n, m;
		cin >> n >> m;
		char cache[1000][1001]; memset(cache, '1', sizeof(cache));
		for (int row = 0; row < n; row++) {
			scanf("%s", cache[row]);
		}
		//STL 큐를 생성
		queue<pair<int, int> > q;
		//첫줄을 돌면서
		for (int row = 0, col = 0; col < m; col++) {
			//구멍하나하나 마다 따로 bfs를 시전한다
			//방문하지 않았다면 방문으로 기록하고 큐에 추가
			if (cache[row][col] == '0') {
				q.push(make_pair(row, col));
				cache[row][col] = '1';
				//4방향에 대해서 y,x로 기록
				int dirs[4][2] = { { -1,0 },{ 0,1 },{ 0,-1 },{ 1,0 } };
				bool upToDown = false;
				pair<int, int> temp;
				//해답을 찾거나 큐가 빌때까지
				while (!(q.empty() || upToDown)) {
					//큐에 맨앞에서 4방향 검사하여 추가
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
				//큐가 비거나 해답을 찾은뒤 결과에 따른 출력
				if (upToDown == true) { cout << "YES" << endl; return 0; }
			}

		}//모든 구멍을 살펴보았음
		cout << "NO" << endl;
		return 0;
	}
}