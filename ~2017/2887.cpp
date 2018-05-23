#include <cstdio>
#include <algorithm>
#include <vector>
#include<cstring>
using namespace std;
int n;
int p[100010];
vector<pair<int, pair<int, int>>> adj;
vector<pair<int, int>> x, y, z;
int find(int a) {
	if (p[a] == -1) return a;
	return p[a] = find(p[a]);
}
bool merege(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	p[b] = a;
	return true;
}

int main() {
	scanf("%d", &n);
	adj.resize((n - 1) * 3);
	x.resize(n);
	y.resize(n);
	z.resize(n);
	memset(p, -1, sizeof(p));
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x[i].first, &y[i].first, &z[i].first);
		x[i].second = y[i].second = z[i].second = i;
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());
	for (int k = 0, i = 0; i < n - 1; i++) {
		adj[k++] = { abs(x[i].first - x[i + 1].first),{ x[i].second, x[i + 1].second } };
		adj[k++] = { abs(y[i].first - y[i + 1].first),{ y[i].second, y[i + 1].second } };
		adj[k++] = { abs(z[i].first - z[i + 1].first),{ z[i].second, z[i + 1].second } };
	}
	sort(adj.begin(), adj.end());
	int cnt = 0;
	int ans = 0;
	for (int u, v, i = 0; i < adj.size(); i++) {
		u = adj[i].second.first;
		v = adj[i].second.second;
		if (merege(u, v)) {
			cnt++;
			ans += adj[i].first;
			if (cnt == n - 1)
				break;
		}
	}
	printf("%d", ans);
	return 0;
}