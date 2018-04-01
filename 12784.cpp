#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
int n, m;
bool visited[1001];

vector<vector<pair<int, int>> >v;

int dfs(int pos, int ex, int val) {
	visited[pos] = true;
	if (v[pos].size() == 0)
		return 0;

	if (v[pos].size() == 1) {
		return val;
	}
	int total = 0;

	for (int i = 0; i < v[pos].size(); i++) {
		int to = v[pos][i].first;
		if (!visited[to]) {
			total += dfs(to, pos, v[pos][i].second);
		}
	}
	return min(total, val);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		v.clear();
		scanf("%d %d", &n, &m);
		v.resize(n + 1);
		memset(visited, 0, sizeof(visited));

		int from, to, cost;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &from, &to, &cost);
			v[from].push_back({ to,cost });
			v[to].push_back({ from,cost });
		}
		int ans = 0;
		visited[1] = true;
		for (int i = 0; i < v[1].size(); i++) {
			visited[v[1][i].first] = true;
			ans += dfs(v[1][i].first, 1, v[1][i].second);
		}
		printf("%d\n", ans);
	}
	return 0;
}