#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n, m;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
int statue[100][100];
int check[100][100];
int table[100][100];
queue<pair<int,int>>q;

void bfs(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int tr = r + dr[i];
		int tc = c + dc[i];
		if (tr >= 0 && tr < n && tc >= 0 && tc < m &&check[tr][tc] == false) {
			if (table[tr][tc] == 0) {
				check[tr][tc] = true;
				bfs(tr, tc);
			}
			if (table[tr][tc] == 1) {
				statue[tr][tc]++;
				if (statue[tr][tc] >= 2) {
					q.push({ tr, tc });
					check[tr][tc] = true;
				}
					
			}
				
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			scanf("%d", &table[i][j]);
		}
	check[0][0] = true;
	bfs(0, 0);

	int cnt = 0;
	while (!q.empty()) {
		int siz = q.size();
		cnt++;
		for (int i = 0; i < siz; i++) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			int cnt = 0;
			check[r][c] = true;
			table[r][c] = 0;
			statue[r][c] = 0;
			bfs(r, c);
		}
	}

	printf("%d", cnt);
}