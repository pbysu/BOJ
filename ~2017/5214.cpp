#include<queue>
#include<algorithm>
#include<vector>

using namespace std;
int n, k, m, tmp;
vector<vector<int>>edge;
vector<vector<int>> adj;
queue<pair<int,int>> q;
vector<bool> check;
vector<bool> adj_check;
int main() {
	scanf("%d %d %d", &n, &k, &m);
	adj.resize(m + 1);
	adj_check.resize(m + 1);
	edge.resize(n + 1);
	check.resize(n + 1);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			scanf("%d", &tmp);
			adj[i].push_back(tmp);
			edge[tmp].push_back(i);
		}
	}
	q.push({ 1,0 });
	check[1] = true;
	bool jd = false;
	int ans = 0;
	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < edge[now].size(); i++) {
			if (!adj_check[edge[now][i]]) {
				for (int j = 0; j < adj[edge[now][i]].size(); j++) {
					if (!check[adj[edge[now][i]][j]]) {
						if (adj[edge[now][i]][j] == n) {
							jd = true;
							ans = cnt + 1;
							break;
						}
						check[adj[edge[now][i]][j]] = true;
						q.push({ adj[edge[now][i]][j],cnt + 1 });
					}
				}
			}
			adj_check[edge[now][i]] = true;
			if (jd) break;
		}
		if (jd) break;
	}
	if (jd) printf("%d", ans+1);
	else printf("-1");
	return 0;
}