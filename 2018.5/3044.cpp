#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<vector<int>> adj;
int n, m, u, v, de[10001], cost[10001];
queue<int> q;
const int mod = 1e9;

void bfs() {
	while (q.size()) {
		int cur = q.front(); q.pop();
		for (auto next : adj[cur]) {
			cost[next] = (cost[next] + cur[cost])%mod;
			if (--de[next] == 0) q.push(next);
		}
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		de[v]++;
	}
	for (int i = 1; i <= n; i++) {
		if (de[i] == 0)
			q.push(i);
	}
	cost[1] = 1;
	bfs();
	if (de[2] > 0) {
		printf("inf\n");
		return 0;
	}
	else
		printf("%d\n", cost[2]);

	return 0;
}