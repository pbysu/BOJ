#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 987654321
using namespace std;

int n, x, m;
int from, to, cost;
vector<pair<int, int>> edge[10001];
vector<pair<int, int>> revedge[10001];
vector<int>dist(3001, INF);

int reverseDistra(int src) {
	int ans = 0;
	vector<int>redist(m + 1, INF);
	priority_queue <pair<int, int>> pq;
	redist[src] = 0;
	pq.push({ src, 0 });
	while (!pq.empty()) {
		int here = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();
		for (int i = 0; i < revedge[here].size(); i++) {
			int end = revedge[here][i].first;
			int pluscost = revedge[here][i].second + cost;
			if (redist[end] > pluscost) {
				redist[end] = pluscost;
				pq.push({ end,-pluscost });
			}
		}
	}
	int MAX = 0;
	for (int i = 1; i <= n; i++) {

			MAX = max(MAX, dist[i] + redist[i]);

	}
	return MAX;
}
void distra(int src) {
	int ans = 0;

	priority_queue <pair<int,int>> pq;
	dist[src] = 0;
	pq.push({ src, 0 });
	while (!pq.empty()) {
		int here = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();
		for (int i = 0; i < edge[here].size(); i++) {
			int end = edge[here][i].first;
			int pluscost = edge[here][i].second + cost;

			if (dist[end] > pluscost) {
				dist[end] = pluscost;
				pq.push({ end,-pluscost });
			}
		}
	}
}
int main() {

	scanf("%d %d %d", &n, &m, &x);
	int t = m;
	while (t--) {
		scanf("%d%d%d", &from, &to, &cost);
		edge[from].push_back({ to, cost });
		revedge[to].push_back({ from,cost });
	}

	distra(x);
	int ans = reverseDistra(x);

	printf("%d", ans);
	return 0;
}