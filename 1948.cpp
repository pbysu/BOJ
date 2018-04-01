#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m, s, e;
vector <vector<pair<int, int>>> adj, rev;
int indegre[10001], dp[10001];
bool edge[10001][10001];
queue<int> q;
int main() {
	scanf("%d%d", &n, &m);
	adj.resize(n + 1);
	rev.resize(n + 1);
	for (int u, v, c, i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back({ v, c });
		indegre[v]++;
		rev[v].push_back({ u, c });
	}
	scanf("%d %d", &s, &e);
	q.push(s);
	while (!q.empty()) {
		int pos = q.front();
		q.pop();
		for (pair<int, int> next : adj[pos]) {
			if (dp[next.first] < dp[pos] + next.second) {
				dp[next.first] = dp[pos] + next.second;
			}
			indegre[next.first]--;
			if (indegre[next.first] == 0) {
				q.push(next.first);
			}
		}
	}
	q.push(e);
	int cnt = 0;
	while (!q.empty()) {
		int pos = q.front();
		q.pop();
		for (pair<int, int> next : rev[pos]) {
			if (!edge[pos][next.first] && dp[next.first] == dp[pos] - next.second) {
				edge[pos][next.first] = true;
				q.push(next.first);
				cnt++;
			}
		}
	}
	printf("%d\n", dp[e]);
	printf("%d", cnt);
	return 0;
}