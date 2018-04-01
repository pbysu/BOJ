#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;
struct Edge {
	int v, cap, cost, rev;
	Edge(int v, int cap, int cost, int rev) :
		v(v), cap(cap), cost(cost), rev(rev) {}
};
int N, M, S, T, sz;
vector<vector<Edge>>adj;
vector<int> p, pdx;
void addEdge(int u, int v, int cap, int cost) {
	adj[u].emplace_back(v, cap, cost, adj[v].size());
	adj[v].emplace_back(u, 0, -cost, adj[u].size() - 1);
}
bool spfa() {
	vector<int> dist(sz, INF);
	vector<bool> inQ(sz, false);
	queue<int> q;
	q.push(S), inQ[S] = 1, dist[S] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop(); inQ[cur] = false;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].v;
			int cap = adj[cur][i].cap;
			int cost = adj[cur][i].cost + dist[cur];
			if (cap && dist[next] > cost) {
				dist[next] = cost;
				p[next] = cur;
				pdx[next] = i;
				if (!inQ[next]) q.push(next), inQ[next] = true;
			}
		}
	}
	return dist[T] != INF;
}

int solve() {
	int totalFlow = 0, totalCost = 0;
	while (spfa()) {
		int flow = INF;
		for (int i = T; i != S; i = p[i]) {
			int prev = p[i], idx = pdx[i];
			flow = min(flow, adj[prev][idx].cap);
		}
		for (int i = T; i != S; i = p[i]) {
			int prev = p[i], idx = pdx[i];
			adj[prev][idx].cap -= flow;
			adj[i][adj[prev][idx].rev].cap += flow;
			totalCost += adj[prev][idx].cost*flow;
		}
	}
	return totalCost;
}
int main() {
	scanf("%d %d", &N, &M);
	S = 0;
	T = N + M + 1;
	sz = N + M + 2;

	adj.resize(sz);
	p.resize(sz);
	pdx.resize(sz);

	for (int ca, i = 1+M; i <=M+N; i++) {
		scanf("%d", &ca);
		addEdge(i, T, ca, 0);
	}

	for (int ca, i = 1; i <=M; i++) {
		scanf("%d", &ca);
		addEdge(S, i, ca, 0);
	}

	for (int cost, i = 1; i <=M; i++) {
		for (int j = M+1; j <=M+N; j++) {
			scanf("%d", &cost);
			addEdge(i, j, INF, cost);
		}
	}
	printf("%d", solve());
	return 0;
}