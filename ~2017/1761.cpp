#include<cstdio>
#include<vector>
#define Max 18
using namespace std;
int n, m;
struct Node{
	int node;
	int cost;
	Node(int n, int c) {
		node = n;
		cost = c;
	}
};
struct Depth {
	int depth;
	int cost;
	Depth() {
		depth = -1;
		cost = 0;
	}
	Depth(int d, int c) {
		depth = d;
		cost = c;
	}
};
vector<Node> adj[40010];
Depth depth[40010];
int parent[40010][Max];

void findDepth(int pos, int dep, int cost) {

	for (Node next : adj[pos]) {
		if (depth[next.node].depth == -1) {
			parent[next.node][0] = pos;
			depth[next.node].depth = dep+1;
			depth[next.node].cost = cost+next.cost;
			findDepth(next.node, dep+1,cost + next.cost);
		}
	}
}

int lca(int u, int v) {
	if (depth[u].depth < depth[v].depth) swap(u, v);
	int dif = depth[u].depth - depth[v].depth;

	for (int j = 0; dif; j++) {
		if (dif % 2) u = parent[u][j];
		dif /= 2;
	}

	if (u != v) {
		for (int j = Max-1; j >= 0; j--) {
			if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
				u = parent[u][j];
				v = parent[v][j];
			}
		}
		u = parent[u][0];
	}
	return u ;
}

int main() {
	scanf("%d", &n);
	for (int u, v, c, i = 0; i < n-1; i++) {
		scanf("%d %d %d", &u, &v, &c);
		u--; v--;
		adj[u].emplace_back(v,c);
		adj[v].emplace_back(u,c);
	}
	
	for (int i = 0; i < n; i++) {
		depth[i].depth = -1;
		depth[i].cost = 0;
	}
	depth[0].depth = 0;
	for (int j = 0; j < 18; j++) {
		for (int i = 0; i < n; i++) {
			parent[i][j] = -1;
		}
	}
	findDepth(0, 0, 0);
	for (int j = 0; j < Max; j++) {
		for (int i = 0; i < n; i++) {
			if(parent[i][j] != -1)
				parent[i][j + 1] = parent[parent[i][j]][j];
		}
	}

	scanf("%d", &m);
	int u, v;
	int ret = 0;
	while (m--) {
		ret = 0;
		scanf("%d %d", &u, &v);
		u--; v--;
		ret = depth[u].cost;
		ret += depth[v].cost;
		ret -= 2*depth[lca(u, v)].cost;
		printf("%d\n", ret);
	}
	return 0;
}