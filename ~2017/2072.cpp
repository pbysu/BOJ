#include<iostream>
#include<cstring>
using namespace std;
int n;
int table[101][101];
pair<int, int> tmp;
int dr[8] = {0,  0, 1, -1, 1,  -1,  -1, 1};
int dc[8] = {1, -1, 0, 0,  1,  -1,  1,- 1 };

int dfs(int r, int c, int dir, int dol) {
	int ret = 1;
	int tr = r + dr[dir];
	int tc = c + dc[dir];
	if (table[tr][tc] == dol) {
		ret += dfs(tr, tc, dir, dol);
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	memset(table, -1, sizeof(table));
	int win = 0;
	for (int r, c, i = 0; i < n; i++) {
		scanf("%d %d", &r, &c);
		if (win == 0) {
			table[r][c] = i % 2;
			for (int j = 0; j < 8; j += 2) {
				if (dfs(r, c, j, i % 2) + dfs(r, c, j + 1, i % 2)-1 == 5) {
					win = i + 1;
					break;
				}
			}
		}
	}
	if (!win) printf("-1");
	else printf("%d", win);
	return 0;
}