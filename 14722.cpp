#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef pair<int, int> pii;
int n, table[1010][1010], dp[1010][1010][3], dr[] = { 1,0 }, dc[] = { 0,1 };
vector<pii> start;
int func(int r, int c,int state) {
	int &ret = dp[r][c][state];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 0; i < 2; i++) {
		int tr = r + dr[i];
		int tc = c + dc[i];
		if (tr > 0 && tr <= n &&tc > 0 && tc <= n) {
			ret = max(ret, func(tr, tc, state));
			if (table[tr][tc] == (state + 1) % 3) {
				ret = max(ret, func(tr, tc, (state + 1) % 3) + 1);
			}
		}
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &table[i][j]);
			if (table[i][j] == 0)
				start.push_back({ i,j });
		}
	}
	int ans = 0;
	for (int i = 0; i < start.size(); i++) {
		ans = max(ans, func(start[i].first, start[i].second, 0)+1);
	}
	printf("%d", ans);
	return 0;
}