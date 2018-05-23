#include <cstdio>
#include <vector>
using namespace std;
int n, m, u, v;
vector<vector<int>> adj;

bool visited[1001];
void dfs(int cur) {
	visited[cur] = true;
	//for (auto next : adj[cur]) {
	//	if(!visited[next])
	//		dfs(next);
	//}
	for (int i = 0; i < adj[cur].size(); i++) {
		int next = adj[cur][i];
		if (!visited[next])
			dfs(next);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
	}

	printf("%d", ans);
	return 0;
}