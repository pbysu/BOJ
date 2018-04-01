#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int t, n, m, w, a, b, c, cycle;
int dist[505];
vector<vector<pair<int, int>>> vt;
int main() {
	scanf("%d", &t);
	while (t--) {
		cycle = false;
		scanf("%d%d%d", &n, &m, &w);
		vt.clear();
		vt.resize(n + 1);
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			vt[a].emplace_back(b, c);
			vt[b].emplace_back(a, c);
		}
		for (int i = 0; i < w; i++) {
			scanf("%d%d%d", &a, &b, &c);
			vt[a].emplace_back(b, -c);
		}
		for (int i = 2; i <= n; i++)
			dist[i] = INF;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (auto k : vt[j]) {
					int there = k.first;
					int d = k.second;
					if (dist[j] != INF && (dist[there]>dist[j] + d)) {
						dist[there] = dist[j] + d;
						if (i == n)cycle = true;
					}
				}
			}
		}
		if (cycle)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}