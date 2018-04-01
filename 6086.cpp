#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define INF 987654321
#define sink 25
#define source 0
using namespace std;
int n, z;
char x, y;
int level[60], work[60];
struct Edge {
	int v, cap, rev;
	Edge(int v, int cap, int rev) :v(v), cap(cap), rev(rev) {};
};
vector<Edge> adj[60];
void addEdge(int s, int e, int c) {
	adj[s].emplace_back(e, c, (int) adj[e].size());
	adj[e].emplace_back(s, c, (int) adj[s].size() - 1);
}
bool bfs() {
	memset(level, -1, sizeof(level));
	queue<int> q;
	level[source] = 0;
	q.push(source);
	while (q.size()) {
		int pos= q.front();
		q.pop();
		for (Edge next : adj[pos]) {
			int there = next.v;
			int cap = next.cap;
			if (level[there] == -1 && cap> 0) {
				level[there] = level[pos] + 1;
				q.push(there);
			}
		}
	}
	return level[sink] != -1;
}
int dfs(int here, int crtcap) {
	if (here == sink)return crtcap;
	for (int &i = work[here]; i < adj[here].size(); i++) {
		int there = adj[here][i].v;
		int cap = adj[here][i].cap;
		if (level[here] + 1 == level[there] && cap > 0) {
			int c = dfs(there, min(crtcap, cap));
			if (c > 0) {
				adj[here][i].cap -= c;
				adj[there][adj[here][i].rev].cap += c;
				return c;
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c %c %d", &x, &y, &z);

		int a, b;

		if ('A' <= x && x <= 'Z') a = x - 'A';
		else a = x - 'a' + 26;
		if ('A' <= y && y <= 'Z')b = y - 'A';
		else b = y - 'a' + 26;
		addEdge(a, b, z);
	}
	int ret = 0;
	while (bfs()) {
		memset(work, 0, sizeof(work));
		while (1) {
			int flow = dfs(source, INF);
			if (!flow)break;
			ret += flow;
		}
	}

	printf("%d", ret);
	return 0;
}