#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define INF 1e9
using namespace std;
int n, map[11][11];
int dr[] = { 0,0,0,1,-1 };
int dc[] = { 0,-1,1,0,0 };
bool visited[11][11];

int func(int r, int c, int cnt) {
	if (cnt == 0) return 0;
	int ret = 0;
	int tmp = 0;
	if (c >= n - 1) r++, c = 1;
	if (r >= n - 1) {
		return INF;
	}
	ret = func(r, c + 1, cnt);

	bool jd = true;
	for (int i = 0; i < 5; i++) {
		if (visited[r + dr[i]][c + dc[i]])
		{
			tmp = func(r, c + 1, cnt); jd = false; break;
		}
	}
	if (jd) {
		visited[r][c] = true;
		for (int i = 0; i < 5; i++) {
			visited[r + dr[i]][c + dc[i]] = true;
			tmp += map[r + dr[i]][c + dc[i]];
		}
		tmp += func(r, c + 2, cnt - 1);
		for (int i = 0; i < 5; i++) {
			visited[r + dr[i]][c + dc[i]] = false;
		}
	}

	return ret = min(tmp,ret);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		scanf("%d", &map[i][j]);
	int ans = func(1, 1,3);
	printf("%d", ans);
	return 0;
}