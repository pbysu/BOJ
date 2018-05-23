#include<iostream>
#include<algorithm>
using namespace std;


int parent[1000001];

int n, m;
int a, b, c;
int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}


void merge(int u, int v) {
	u = find(u);
	v = find(v);
	parent[u] = v;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) {
			int p1 = find(b);
			int p2 = find(c);
			if (p1 != p2) merge(p1, p2);
		}
		else {
			int p1 = find(b);
			int p2 = find(c);
			if (p1 != p2) {
				printf("NO\n");
			}
			else printf("YES\n");
		}
	}
	return 0;
}