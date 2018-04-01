#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
vector<vector<int>> adj;
int main() {
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int u,v, i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	scanf("%d", &m);
	for (int t, a, i = 0; i < m; i++) {
		scanf("%d %d", &t, &a);
		if (t == 2) {
			printf("yes\n");
		}
		else {
			if (adj[a].size()<=1) printf("no\n");
			else printf("yes\n");
		}
	}
	return 0;
}