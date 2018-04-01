#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int INF = 987654321;
int capacity[404][404];
int flow[404][404];
int n, m;

int networkFlow(int src, int sin) {
	memset(flow, 0, sizeof(flow));
	int totalFlow = 0;
	while (true) {
		vector<int> parent(n+m+2, -1);
		queue<int> q;
		parent[src] = src;
		q.push(src);

		while (!q.empty() && parent[sin] == -1) {
			int here = q.front(); q.pop();
			for (int there = 0; there < n+m+2; ++there) {
				if (capacity[here][there] - flow[here][there] > 0
					&& parent[there] == -1) {
					q.push(there);
					parent[there] = here;
				}
			}
		}

		if (parent[sin] == -1)	 break;

		int amount = INF;
		for (int p = sin; p != src; p = parent[p])
			amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);

		for (int p = sin; p != src; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}

	return totalFlow;
}


int main() {


	scanf("%d %d", &n, &m);
	int a, tmp;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		capacity[0][i] = 1;
		for(int j =0; j< a; j++) {
			scanf("%d", &tmp);
			capacity[i][tmp+n] = 1;
		}
	}
	for (int i = n+1; i < n + m + 1; i++) {
		capacity[i][n + m + 1] = 1;
	}

	printf("%d", networkFlow(0, n+m+1));
	return 0;
}