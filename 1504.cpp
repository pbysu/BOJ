#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define INF 287654321
using namespace std;
int n, e;
int must[2];
typedef long long ll;
vector<vector<pair<int,ll>>> adj;

ll dijkstra(int s, int t) {
	vector<ll> dik;
	dik.resize(n, INF);
	dik[s] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.push({ 0, s });
	while (!pq.empty()) {
		pair<ll, int> pos = pq.top();
		pq.pop();

		for (pair<int, ll> next : adj[pos.second]) {
			ll plusCost = pos.first*-1 + next.second;
			int there = next.first;
			if (dik[next.first] > plusCost) {
				dik[next.first] = plusCost;
				pq.push({ -1 * plusCost, there });
			}
		}
	}
	return dik[t];
}
int main() {
	scanf("%d %d", &n, &e);
	adj.resize(n + 1);
	ll c;
	for ( int u,v, i = 0; i < e; i++) {
		scanf("%d %d %lld", &u, &v, &c);
		u--, v--;
		adj[u].push_back({ v,c });
		adj[v].push_back({ u,c });
	}
	scanf("%d%d", &must[0], &must[1]);
	must[0]--;
	must[1]--;

	ll ans = min(dijkstra(0, must[0]) + dijkstra(must[0], must[1]) + dijkstra(must[1], n - 1),dijkstra(0, must[1]) + dijkstra(must[1], must[0]) + dijkstra(must[0], n - 1));
	if (ans >= INF)
		ans = -1;
	printf("%lld", ans);

	return 0;
}