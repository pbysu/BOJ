#include<iostream>
#include<vector>
using namespace std;

int n;
int h = 20;
int timer = 1;

vector<int> graph[50001];

int tin[50001];
int tout[50001];

int p[50001][21];

void dfs(int cur, int parent) {
	tin[cur] = timer++;
	p[cur][0] = parent;

	for (int i = 1; i <= h; i++) {
		if (p[cur][i - 1]) {
			p[cur][i] = p[p[cur][i - 1]][i - 1];
		}
	}

	for (int i = 0; i < graph[cur].size(); i++) {
		if (!tin[graph[cur][i]]) {
			dfs(graph[cur][i], cur);
		}
	}

	tout[cur] = timer++;
}

bool isUpper(int u, int v) {
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
	if (isUpper(u, v)) return u;
	if (isUpper(v, u)) return v;

	for (int i = h; i >= 0; i--) {
		if (p[u][i] && !isUpper(p[u][i], v)) {
			u = p[u][i];
		}
	}
	return p[u][0];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1, 0);

	int m;
	scanf("%d", &m);
	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", lca(u, v));
	}
}