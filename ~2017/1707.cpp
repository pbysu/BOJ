#include<iostream>
#include<vector>

using namespace std;
vector<int> color;
int t;
vector<vector<int>>adj;
bool dfs(int node, bool jd) {
	color[node] = jd + 1;
	for (int i = 0; i < adj[node].size(); i++) {
		if (color[adj[node][i]] == jd+1) {
			return false;
		}
		else if(color[adj[node][i]]==0) {
			if (!dfs(adj[node][i], !jd))
				return false;
		}
	}

	return true;
}
int main() {
	scanf("%d", &t);
	int n, m;
	while (t--) {
		adj.clear();
		color.clear();

		scanf("%d %d", &n, &m);
		adj.resize(n);
		color.resize(n);
		for (int a, b, i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			adj[a - 1].push_back(b - 1);
			adj[b - 1].push_back(a - 1);
		}
		bool jd = true;

		for (int i = 0; i < n; i++) {
			if (color[i] == false) {
				if (!dfs(i, true)) {
					jd = false;
					break;
				}
			}
		}
		if (jd)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}