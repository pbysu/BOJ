#include<iostream>
#include <algorithm>
#include<cstring>
using namespace std;

struct Edge {
	int u, v, w;
	Edge() : Edge(-1, -1, 0) {}
	Edge(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {
	}
};

Edge edge[100000];
int uf[10001];

int find(int a) {
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return false;

	uf[b] = a;
	return true;
}


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int v, u, w;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &v, &u, &w);
		edge[i] = Edge(v-1, u-1, w);
	}
	
	sort(edge, edge + m, [](Edge p, Edge q) {return p.w < q.w; });

	fill(uf, uf+n, -1);
	int res = 0;
	int cnt = 0;

	for (int i = 0; i < m; i++) {
		if (merge(edge[i].u, edge[i].v)) {
			res += edge[i].w;
			if (++cnt == n-1) break;
		}
	}

	printf("%d", res);
	return 0;
}