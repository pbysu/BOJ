#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, u, v, s;
vector<vector<int>> adj;
vector<vector<int>> rev;
priority_queue<int> q;

void dfs(int cur) {
	if (adj[cur].size() == 1)
		q.push(-adj[cur][0]), dfs(adj[cur][0]);
}

int revDfs(int cur) {
	while (rev[cur].size() == 1) {
		cur = rev[cur][0];
	}
	return cur;
}
int main() {
	scanf("%d", &n);
	adj.resize(n + 1);
	rev.resize(n + 1);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		rev[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!adj[i].size()) {
			s = revDfs(i);
			break;
		}
	}

	if (rev[s].size()) {
		q.push(-s);
	}
	dfs(s);

	while (q.size()) {
		printf("%d\n", -q.top());
		q.pop();
	}
	return 0;
}