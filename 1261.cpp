#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define INF 987654321
using namespace std;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int table[101][101];
int dp[101][101];
int n, m;
void func(int r, int c, int cnt) {
	int& ret = dp[r][c];
	ret = cnt;
	for (int i = 0; i < 4; i++) {
		int tc = c + dc[i];
		int tr = r + dr[i];
		if (tr >= 0 && tr < m && tc >= 0 && tc < n) {
			if (table[tr][tc] == 1 && cnt + 1 < dp[tr][tc])
				func(tr, tc, cnt + 1);
			if (table[tr][tc] == 0 && cnt < dp[tr][tc])
				func(tr, tc, cnt);
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &table[i][j]);
		}
	}
	dp[0][0] = 0;

	func(0, 0, 0);
	printf("%d", dp[m - 1][n - 1]);
	return 0;
}