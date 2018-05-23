#include<iostream>
#include<queue>
using namespace std;
int table[1000][1000];
int n, m;
typedef pair<int, int> pii;
queue<pii> q;
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { 1,-1, 0, 0 };
int main() {

	scanf("%d %d", &m, &n);
	int check = 0;
	int minus = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &table[i][j]);
			if (table[i][j]==1)
				check ++,q.push({ i,j });
			if (table[i][j] == -1)
				minus++;
		}
	int cnt = -1;
	
	while (!q.empty()) {
		int siz = q.size();
		cnt++;
		for (int i = 0; i < siz; i++) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int tr = r + dr[j];
				int tc = c + dc[j];
				if (tr >= 0 && tr < n && tc >= 0 && tc < m && table[tr][tc] == 0) {
					q.push({ tr,tc });
					table[tr][tc] = 1;
					check++;
				}
			}
		}
	}
	if (check == n*m-minus)
		printf("%d", cnt);
	else
		printf("%d", -1);

}