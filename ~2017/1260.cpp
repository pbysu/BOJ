#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m, v;
vector<vector<int>> adj;
vector<bool> visited;


int s, e;


void dfs(int node) {
	visited[node] = true;
	printf("%d ", node);
	
	for (int i = 0; i < adj[node].size(); i++) {
		int next = adj[node][i];

		if (visited[next] == false) {
			dfs(next);
		}
	}
}


void bfs(int node) {
	queue<int> qsearch;

	visited[node] = true;
	qsearch.push(node);

	while (!qsearch.empty()) {

		int here = qsearch.front();
		

		printf("%d ", here);
		qsearch.pop();

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];

			if (!visited[next]) {
				visited[next] = true;
				qsearch.push(next);
			}
		}
	}


}



int main() {
	scanf("%d %d %d", &n, &m, &v);
	adj.resize(n+1);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	visited = vector<bool>(n+1, false);
	for (int i = 0; i < adj.size(); i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	
	dfs(v);

	visited = vector<bool>(n + 1, false);
	printf("\n");
	bfs(v);

	return 0;
}