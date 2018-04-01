#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
int n;
int cost[10001];
int dp[10001][2];
vector<vector<int>> adj;
priority_queue<int, vector<int>,greater<int>> pq;
int func(int ex, int pos, int use) {
	int &ret = dp[pos][use];
	if (ret != -1)
		return ret;
	ret = 0;
	int tmp = 0;
	if (use == 0) {
		for (int next : adj[pos]) {
			if (ex == next)continue;
			int u = func(pos, next, 1) + cost[next];
			int nu = func(pos, next, 0);
			if (u > nu) {
				ret += u;
			}
			else
				ret += nu;
		}
	}
	else {
		for (int next : adj[pos]) {
			if (next== ex) continue;
			ret += func(pos, next, 0);
		}
	}
	return ret;
}
void trace(int ex, int pos, int use) {
	if (use==1) {
		pq.push(pos);
		for (auto next : adj[pos]) {
			if (ex == next) continue;
			trace(pos, next, 0);
		}
	}
	else {
		for (auto next : adj[pos]) {
			if (ex == next) continue;
			if (dp[next][1]+cost[next] >= dp[next][0])
				trace(pos, next, 1);
			else
				trace(pos, next, 0);
		}
	}
}
int main() {
	scanf("%d", &n);
	adj.resize(n+1);
	memset(dp, -1, sizeof(dp));
	cost[0] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &cost[i]);
	for (int u, v, i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	adj[0].push_back(1);
	adj[1].push_back(0);

	printf("%d\n", func(0,0,0));
	trace(0, 0,0);
	while (!pq.empty()){
		printf("%d ", pq.top());
		pq.pop();
	}
	return 0;
}