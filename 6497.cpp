#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
int p[100010];
int find(int cur) {
	if (p[cur] == -1)return cur;
	return p[cur] = find(p[cur]);
}
bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	p[v] = u;
	return true;
}
struct Edge {
	int u, v, c;
	Edge() : Edge(-1, -1, 0) {}
	Edge(int u, int v, int c) : u(u), v(v), c(c) {}
};
int n; int m;

int main() {
	bool jd=true;
	while (jd) {

		vector <Edge>adj;
		scanf("%d\n%d", &n, &m);
		if (n == m&&n == 0)	 return 0;
		memset(p, -1, sizeof(p));
		adj.resize(m);
		int total = 0;
		for (int u, v, c, i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &c);
			adj[i] = Edge(u, v, c);
			total += c;
		}
		sort(adj.begin(), adj.end(), [](Edge p, Edge q) {
			if (p.c != q.c)
				return p.c < q.c;
			else
				return p.c<q.c;
		});
		int ret = 0;
		int cnt = 0;
		for (int i = 0; i < 2 * m; i++) {
			if (merge(adj[i].u, adj[i].v)) {
				ret += adj[i].c;
				if (++cnt == n - 1)break;
			}
		}
		printf("%d\n", total - ret);
	}
	
	return 0;
}