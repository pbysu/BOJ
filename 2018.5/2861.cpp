#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
queue<int> q;
int ind[200001], n, give[200001],
	state[200001],adj[200001], u, v;
bool visited[200001];
int ans;

void func(int cur) {
	visited[cur] = true;
	if (give[cur] - state[cur]>0)
		ans += give[cur] - state[cur];
	state[adj[cur]] += give[cur];
	if (!visited[adj[cur]]) func(adj[cur]);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &u, &v);
		give[i] += v;
		adj[i] = u;
		ind[u]++;
	}
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) q.push(i);
	}
	while (q.size()) {
		int cur = q.front(); q.pop();
		int next = adj[cur]; ind[next]--;
		if (give[cur] - state[cur] > 0)
			ans += give[cur] - state[cur];
		state[adj[cur]] += give[cur];
		if (ind[next] == 0)q.push(next);
	}


	for(int i =1; i<=n; i++) {
		if (ind[i]!=0&& !visited[i]) {
			int mini, cost = 1e9, idx = i;
			while (1) {
				if (cost > give[idx] - state[idx]) {
					mini = idx;
					cost = give[idx] - state[idx];
				}
				idx = adj[idx];
				if (idx == i)break;
			}
			func(mini);
		}
	}
	printf("%d", ans);
	return 0;
}