#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;
int n, m, k;
vector<vector<pair<int, int>>> edge;

int dijstra(int src) {
	priority_queue < pair<int, pair<int, int>>> pq;
	pq.push({ 0,{src, 0} });
	vector<int> dist[21];
	for (int i = 0; i <= 20; i++) {
		dist[i].resize(n + 1, INF);
	}

	while (!pq.empty()) {
		int here = pq.top().second.first;
		int cost = -1 * pq.top().first;
		int tk = pq.top().second.second;
		pq.pop();
		
		for (auto next : edge[here]) {
			int there = next.first;
			int plusCost = next.second + cost;
			if (plusCost < dist[tk][there]) {
				pq.push({ -1 * plusCost,{there, tk} });
				dist[tk][there] = plusCost;
			}
			if (tk + 1 <= k && cost < dist[tk + 1][there]) {
				pq.push({ -1 * cost,{ there, tk + 1 } });
				dist[tk + 1][there] = cost;
			}
		}
	}

	int ret = INF;
	for (int i = 0; i <= k; i++) {
		ret = min(ret, dist[i][n]);
	}
	return ret;
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	int from, to, cost;
	edge.resize(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		edge[from].push_back({ to,cost });
		edge[to].push_back({ from,cost });
	}
	printf("%d", dijstra(1));
}