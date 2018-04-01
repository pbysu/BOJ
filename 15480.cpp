#include<cstdio>
#include<cstring>
#include<vector>
#define Dep 17
using namespace std;
int n, m, u, v, par[100001][18], depth[100001];
vector<vector<int>> adj;

void dfs(int cur) {
	for (int next : adj[cur]) {
		if (!depth[next]) {
			depth[next] = depth[cur]+1;
			par[next][0] = cur;
			dfs(next);
		}
	}
}

int lca(int u, int v) {
	if (depth[u] < depth[v])swap(u, v);
	if (u == v)return u;
	int diff = depth[u] - depth[v];
	for (int i = 0; diff; i++){
		if (diff % 2 == 1) u = par[u][i];
		diff /= 2;
	}
	if (u != v) {
		for (int j = Dep; j >= 0; j--) {
			if (par[u][j] != -1 && par[v][j] != par[u][j]) {
				u = par[u][j];
				v = par[v][j];
			}
		}
		u = par[u][0];
	}
	return u;
}
int main() {
	scanf("%d", &n);
	memset(par, -1, sizeof(par));
	adj.resize(n + 1);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	depth[1] = 1;
	dfs(1);
	for (int j = 0; j <= Dep; j++) {
		for (int i = 0; i <= n; i++) {
			if (par[i][j] != -1) par[i][j+1] = par[par[i][j]][j];
		}
	}
	scanf("%d", &m);
	int ret, t;
	for (int u ,v ,r, i = 0; i < m; i++) {
		scanf("%d %d %d", &r, &u, &v);
		ret = lca(r, u);
		t = lca(u, v);
		ret = depth[ret] > depth[t] ? ret : t;
		t = lca(r, v);
		ret = depth[ret] > depth[t] ? ret : t;
		printf("%d\n", ret);
	}
	return 0;
}