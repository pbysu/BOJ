#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int t, n, m, graph[510][510];
pair<int, int> indegree[510];
vector<int> in;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		in.resize(n);
		memset(graph, 0, sizeof(graph));
		memset(indegree, 0, sizeof(indegree));
		for (int tmp, i = 0; i < n; i++) {
			scanf("%d", &in[i]);
		}
		scanf("%d", &m);
		indegree[in[0]].second = in[0];
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				graph[in[i]][in[j]] = 1;
				indegree[in[j]].first++;
				indegree[in[j]].second = in[j];
			}
		}
		for (int u, v, i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);

			if (graph[u][v]) {
				swap(graph[u][v], graph[v][u]);
				indegree[u].first++;
				indegree[v].first--;
			}
			else {
				swap(graph[u][v], graph[v][u]);
				indegree[u].first--;
				indegree[v].first++;
			}
		}
		queue<int> q, ans;
		for (int i = 1; i <= n; i++) {
			if (indegree[i].first == 0)
				q.push(i), ans.push(i);
		}
		bool jd = true;
		for (int i = 0; i < n; i++) {
			if (q.empty()) {
				printf("IMPOSSIBLE\n");
				jd = false;
				break;
			}
			if (q.size() > 1) {
				printf("?\n");
				jd = false;
				break;
			}
			int tmp = q.front();
			q.pop();
			for (int j = 1; j <= n; j++) {
				if (graph[tmp][j] == 1) {
					indegree[j].first--;
					if (indegree[j].first == 0) {
						q.push(j);
						ans.push(j);
					}
				}
			}
		}

		if (jd) {
			while (!ans.empty()) {
				printf("%d ", ans.front());
				ans.pop();
			}
			printf("\n");
		}
	}
	return 0;
}