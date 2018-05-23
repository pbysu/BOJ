#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int maxNode, m;
vector<vector<int>> adj;
vector<vector<int>> parent;
vector<int> depth;
void makeTree(int curr) {
	for (int next : adj[curr]) {
		if (depth[next] == -1) {
			parent[next][0] = curr;
			depth[next] = depth[curr] + 1;
			makeTree(next);
		}
	}
}

int main() {
	scanf("%d", &maxNode);
	adj.resize(maxNode);
	int MAX = (int)floor(log2(maxNode)) + 1;
	depth.resize(maxNode, -1);
	parent.resize(maxNode, vector<int>(MAX, -1));

	for (int o, t, i = 0; i < maxNode-1; i++) {
		scanf("%d %d", &o, &t);
		o--, t--;
		adj[o].push_back(t);
		adj[t].push_back(o);
	}

	depth[0] = 0;
	makeTree(0);
	for (int j = 0; j < MAX; j++) {
		for (int i = 0; i < maxNode; i++) {
			if (parent[i][j] != -1)
				parent[i][j + 1] = parent[parent[i][j]][j];
		}
	}


	scanf("%d", &m);
	for (int u, v, i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		u--; v--;

		if (depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];

		for (int j = 0; diff; j++) {
			if (diff % 2) u = parent[u][j];
			diff /= 2;
		}

		if (u != v) {
			for (int j = MAX-1; j >= 0; j--) {
				if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			u = parent[u][0];
		}
		printf("%d\n", u + 1);
	}
	return 0;
}