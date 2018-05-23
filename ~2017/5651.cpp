#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 1e9

using namespace std;
vector<pair<int, int>> save;
bool check[301];
struct Edge {
	int v, cap, rev;
	Edge(int v, int cap, int rev)
		:v(v), cap(cap), rev(rev) {}
};
int src, sink, T, N, M, level[301], work[301], ans;
vector<vector<Edge>> adj;
void addEdge(int u, int v, int cap) {
	adj[u].emplace_back(v, cap, adj[v].size());
	adj[v].emplace_back(u, 0, adj[u].size() - 1);
}

bool bfs() {
	memset(level, -1, sizeof(level));
	queue<int> q;
	level[src] = 0;
	q.push(src);
	while (!q.empty()) {
		int pos = q.front();
		q.pop();
		for (Edge node : adj[pos]) {
			int next = node.v;
			int capa = node.cap;
			if (level[next] == -1 && capa > 0) {
				level[next] = level[pos] + 1;
				q.push(next);
			}
		}
	}
	return level[sink] != -1;
}

int dfs(int pos, int flow) {
	if (pos == sink) return flow;
	for (int &i = work[pos]; i < adj[pos].size(); i++) {
		int next = adj[pos][i].v;
		int ca = adj[pos][i].cap;
		int r = adj[pos][i].rev;
		if (level[next] == level[pos] + 1 && ca > 0) {
			int tempFlow = dfs(next, min(flow, ca));
			if (tempFlow > 0) {
				adj[pos][i].cap -= tempFlow;
				adj[next][r].cap += tempFlow;
				return tempFlow;
			}
		}
	}

	return 0;
}
bool func(int pos, int next) {
	if (pos == next) return true;
	check[pos] = true;
	for (Edge node : adj[pos]) {
		if (!check[node.v] && node.cap > 0) {
			if (func(node.v, next)) return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		ans = 0;
		scanf("%d %d", &N, &M);
		save.resize(M);
		adj.clear();
		adj.resize(N + 1);
		src = 1;
		sink = N;
		for (int u, v, c, i = 0; i < M; i++) {
			scanf("%d %d %d", &u, &v, &c);
			addEdge(u, v, c);
			save[i].first = u;
			save[i].second = v;
		}


		while (bfs()) {
			memset(work, 0, sizeof(work));
			if (!dfs(src, INF)) break;
		}

		for (int i = 0; i < M; i++) {
			memset(check, false, sizeof(check));
			if (!func(save[i].first, save[i].second)) ans++;
		}
		printf("%d\n", ans);
	}
}