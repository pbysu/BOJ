#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>p;
vector<int>cnt;
int n, m, u, v;
int find(int pos, int x) {
	if (p[pos] == 0) {
		if (pos != x) {
			cnt[pos] += cnt[x];
			cnt[x] = 0;
		}
		return  pos;
	}	
	p[pos] = find(p[pos], x);
	return p[pos];
}

void merge(int u, int v) {
	u = find(u,u);
	v = find(v,v);
	if (u != v) {
		if (v > u) swap(v, u);
		p[u] = v;
		cnt[v] += cnt[u];
		cnt[u] = 0;
	}
	return;
}
int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	p.resize(n + 1);
	cnt.resize(n + 1,1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		if (find(u, u) != find(v, v))
			merge(u, v);
	}

	printf("%d", cnt[1]-1);
	return 0;
}