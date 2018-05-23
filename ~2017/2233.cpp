#include<iostream>
#include<string>
#include<algorithm>
#define MAX 2002
using namespace std;
string bin;
int n, tn, par[MAX][16], depth[MAX], node[MAX*2], u, v, p, x, y;
int lca(int u, int v) {
	int k = n/2;
	for (int j = 1; j <= 15; j++) {
		for (int i = 1; i <= k; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
	if (depth[u] > depth[v]) {
		swap(u, v);
	}
	for (int i = 15; i >= 0; i--) {
		if (depth[v] - depth[u] >= (1 << i)) {
			v = par[v][i];
		}
	}
	if (u == v) return u;
	for (int i = 15; i >= 0; i--) {
		if (par[u][i] != par[v][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}
int main() {
	scanf("%d", &n);
	cin >> bin;
	n *= 2;

	int cur = 1;
	int id = 0;
	for (int i = 0; i < n; i++) {
		if (bin[i] == '0') {
			par[++id][0] = cur;
			depth[id] = depth[cur] + 1;
			node[i+1] = id;
			cur = id;
		}
		else {
			node[i+1] = cur;
			cur = par[cur][0];
		}
	}
	scanf("%d %d", &u, &v);
	p = lca(node[u], node[v]);
	for (int i = 0; i < n; i++) {
		if (node[i + 1] == p) {
			if (bin[i] == '0')
				x = i + 1;
			if (bin[i] == '1')
				y = i + 1;
		}
	}
	printf("%d %d\n", x, y);
	return 0;
}