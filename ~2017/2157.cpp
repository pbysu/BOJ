#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define INF 987654321
using namespace std;
vector<vector<pair<int, int>>> adj;
int n, m, k, dp[310][301];
int func(int pos, int cnt) {
	if (pos == n)
		return 0;
	if (cnt >m)
		return -INF;
	int &ret = dp[pos][cnt];
	if (ret != -1)
		return ret;
	ret = 0;
	int tmp;
	for (pair<int,int> next : adj[pos]) {
		tmp = func(next.first, cnt+1);
		if (tmp >= 0) {
			ret = max(tmp + next.second, ret);
		}
	}
	if (ret == 0)
		return ret = -INF;
	return ret;
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	adj.resize(n + 1);
	memset(dp, -1, sizeof(dp));
	for (int u, v, cost, i = 0; i < k; i++) {
		scanf("%d %d %d", &u, &v, &cost);
		if (u >= v) continue;
		adj[u].push_back({ v,cost });
	}
	m -= 2;
	printf("%d", func(1, 0));
	return 0;
}