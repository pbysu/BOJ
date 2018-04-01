#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define INF 1e9
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> H;
int dp[101][501];
int u, v, t;
int func(int cur, int tc) {
	int &ret = dp[cur][tc];
	if (ret != -1) return ret;
	if (tc == 0) return ret = H[cur];
	ret = INF;

	for (auto next : adj[cur]) {
		ret = min(ret, func(next, tc - 1));
	}
	return ret;
}
int main() {
	scanf("%d %d", &n, &m);
	H.resize(n+1);
	adj.resize(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &H[i]);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v); adj[u].push_back(v), adj[v].push_back(u);
	}
	scanf("%d", &t);
	memset(dp, -1, sizeof(dp));
	while (t--) {
		scanf("%d %d", &u, &v);
		int ans = func(u, v);
		if (ans == INF)printf("-1\n");
		else printf("%d\n", ans);
	}
	return 0;
}