#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;
vector<pair<int, int>> edge[100001];
int v, e;
int from, to, cost;
int s, last;
int distra(int src) {
	vector<int> dist(v + 1, INF);
	dist[src] = 0;
	
	priority_queue <pair<int, int>> pq;
	pq.push({ src, 0 });
	
	while (!pq.empty()) {
		int cost = -pq.top().second;
		int here = pq.top().first;

		pq.pop();
		for (int i = 0; i < edge[here].size(); i++) {
			int to = edge[here][i].first;
			int costPlus = cost + edge[here][i].second;

			if (costPlus < dist[to]) {
				dist[to] = costPlus;
				pq.push({ to,-costPlus });
			}
		}
	}
	return dist[last];
}

int main() {
	scanf("%d%d", &v, &e);
	while (e--) {
		scanf("%d%d%d", &from, &to, &cost);
		edge[from].push_back({ to, cost });
	}

	scanf("%d%d", &s, &last);

	int result;
	result = distra(s);
	printf("%d", result);
	return 0;
}