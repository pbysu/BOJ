#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<vector<int>> adj;
vector<vector<int>> radj;
int n, m, u, v;
bool mov[100010];
bool rev[100010];
bool solve(int s, bool visited[],vector<vector<int>> edge) {
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (q.size() != 0) {
		int size = q.size();
		for (int i = 0; i < q.size(); i++) {
			int cur = q.front();
			q.pop();
			for (int next : edge[cur]) {
				if (!visited[next]) {
					visited[next] = true;
					q.push(next);
				}
			}
		}
	}
	return false;
}
int main() {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	radj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
	scanf("%d", &u);
	solve(1, mov, adj);
	solve(n, rev,radj);

	for (int i = 0; i < u; i++) {
		scanf("%d", &v);
		if (mov[v] && rev[v]) {
			printf("Defend the CTP\n");
		}
		else
			printf("Destroyed the CTP\n");
	}


	return 0;
}