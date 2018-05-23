#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> adj;
vector<int> root;
priority_queue<int,vector<int>,greater<int>> pq;
int n, m;
int main() {
	scanf("%d %d ", &n, &m);
	adj.resize(n + 1);
	root.resize(n + 1);
	for (int u, v, i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		root[v] ++;
		adj[u].push_back(v);
	}

	for (int i = 1; i <= n; i++) {
		if (!root[i]) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int pos = pq.top();
		printf("%d ", pos);
		pq.pop();
		for (int next : adj[pos]) {
			root[next]--;
			if (!root[next]) {
				pq.push(next);
			}
		}
	}
	return 0;
}