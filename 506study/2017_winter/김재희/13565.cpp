#include<cstdio>

char grid[1000][1000] = { 0 };
bool check = false;

int m, n;

void search(int x, int y){
	if (grid[x][y] == '1') return;
	grid[x][y] = '1';

	if (x == m - 1) check = true;
	if (check) return;

	if (!check){
		if (x + 1 < m)
			search(x + 1, y);
		if (x - 1 > -1)
			search(x - 1, y);
		if (y + 1 < n)
			search(x, y + 1);
		if (y - 1 > -1)
			search(x, y - 1);
	}
}

int _13565(){
	scanf("%d %d", &m, &n);
	char temp[1000];
	for (int i = 0; i < m; i++){
		scanf("%s", temp);
		for (int j = 0; j < n; j++){
			grid[i][j] = temp[j];
		}
	}
	for (int j = 0; j < n; j++){
		search(0, j);
		if (check) break;
	}
	if (check) printf("YES");
	else printf("NO");
}