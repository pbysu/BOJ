#include<iostream>
#include<algorithm>
#include<vector>
#define INF 2e9;
using namespace std;
int n, k, x;
vector<vector<pair<int, int>>> adj;

int parent[100010][21], depth[100010], large[100010][21], small[100010][21];
bool visited[100010];
void findDepth(int pos, int dep) {
	visited[pos] = true;
	depth[pos] = dep;
	for (pair<int, int> next : adj[pos]) {
		if (!visited[next.first]) {
			findDepth(next.first, dep + 1);
			parent[next.first][0] = pos;
			large[next.first][0] = next.second;
			small[next.first][0] = next.second;
		}
	}
}
pair<int, int> lca(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v);
	pair<int, int> ret;
	ret.first = INF;
	ret.second = -INF;
	for (int i = 20; i >= 0; i--) {
		if (depth[v] - depth[u] >= (1 << i)) {
			ret.first = min(ret.first, small[v][i]);
			ret.second = max(ret.second, large[v][i]);
			v = parent[v][i];
		}
	}

	if (u == v) return ret;
	for (int i = 20; i >= 0; i--) {
		if (parent[u][i] != parent[v][i]) {
			ret.first = min(ret.first, min(small[u][i], small[v][i]));
			ret.second = max(ret.second, max(large[u][i], large[v][i]));
			u = parent[u][i];
			v = parent[v][i];
		}
	}

	ret.first = min(ret.first, min(small[u][0], small[v][0]));
	ret.second = max(ret.second, max(large[u][0], large[v][0]));
	return ret;
}

int main() {
	scanf("%d", &n);
	x = 21;
	adj.resize(n + 1);
	for (int u, v, c, i = 1; i < n; i++) {
		scanf("%d %d %d", &u, &v, &c);
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}
	findDepth(1, 0);
	for (int j = 1; j < 21; j++) {
		for (int i = 1; i <= n; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
			large[i][j] = max(large[parent[i][j - 1]][j - 1], large[i][j - 1]);
			small[i][j] = min(small[parent[i][j - 1]][j - 1], small[i][j - 1]);
		}
	}
	scanf("%d", &k);
	pair<int, int> temp;
	for (int u, v, i = 0; i < k; i++) {
		scanf("%d %d", &u, &v);
		temp = lca(u, v);
		printf("%d %d\n", temp.first, temp.second);
	}
	return 0;
}