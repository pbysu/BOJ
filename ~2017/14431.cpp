#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#define INF 987654321
using namespace std;
bool prime[10000000];
int sr, sc, er, ec, n, tr, tc;
vector<pair<int, int>> in;
vector<vector<pair<int, int>>> adj;

void eratos(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (!prime[i]) {
			for (int j = i*i; j <= n; j += i) {
				prime[j] = true;
			}
		}
	}
}
int dist(pair<int, int>p, pair<int, int> q) {
	double x = sqrt((p.first - q.first)*(p.first - q.first) + pow(q.second - p.second, 2));
	return (int)x;
}

int dijsk(int src,int n) {
	vector<int> dij;
	priority_queue<pair<int,int>> pq;
	dij.resize(n, INF);
	dij[src] = 0;
	pq.push({ 0, src });

	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		for (pair<int,int> next : adj[here]) {
			int plusCost = cost + next.second;
			int there = next.first;
			if (dij[there] > plusCost) {
				dij[there] = plusCost;
				pq.push({ -plusCost, there });
			}
		}
	}
	return dij[src + 1];
}
int main() {
	scanf("%d %d %d %d", &sr, &sc, &er, &ec);
	scanf("%d", &n);
	eratos(9999999);
	in.resize(n + 2);
	adj.resize(n + 2);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &in[i].first, &in[i].second);
	}
	in[n] = { sr,sc };
	in[n + 1] = { er,ec };

	for (int i = 0; i < n + 2; i++) {
		for (int j = i+1; j < n + 2; j++) {
			int temp = dist(in[i], in[j]);
			if (prime[temp] == false) {
				adj[i].push_back({ j,temp });
				adj[j].push_back({ i,temp });
			}
		}
	}

	int ans = dijsk(n, n + 2);
	if (ans != INF) {
		printf("%d\n", ans);
	}
	else
		printf("%d\n", -1);

	return 0;
}