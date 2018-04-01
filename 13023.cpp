#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>>adj;
vector<int> depth;
vector<bool>check;
int n, m;
int dfs(int p) {

	int ret = 1;
	check[p] = true;
	for (int next : adj[p]) {
		if (!check[next]) {
			ret = max(dfs(next) + 1, ret);
		}
		if (ret >= 5)
			return ret;
	}
	check[p] = false;
	return ret;
}
int main() {
	scanf("%d %d", &n, &m);
	adj.resize(n);
	depth.resize(n);
	check.resize(n);
	for (int u, v, i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
			ans = dfs(i);
			if (ans >= 5)
				break;
	}
	if (ans >= 5)
		printf("1");
	else
		printf("0");
	return 0;
}