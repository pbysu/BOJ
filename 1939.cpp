#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define INF 2e9
using namespace std;
int n, m, a, b, c, s, t, ans;
vector<vector<pair<int, int>>> adj;
vector<int> cost;
int visited[100001];

bool dfs(int pos, int cnt) {
	if (pos == t) return true;

	visited[pos] = cnt;
	bool ret = false;
	for (pair<int, int> next : adj[pos]) {
		if (visited[next.first]!= cnt&& next.second >= cnt) {
			ret =dfs(next.first, cnt);
			if (ret == true) {
				return true;
			}
		}
	}
	return ret;
}
int main() {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	cost.resize(m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
		cost[i] = c;
	}
	scanf("%d %d", &s, &t);
	sort(cost.begin(), cost.end());
	int left = 0;
	int right = m-1;
	int mid;
	int cnt = 0;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (dfs(1, cost[mid])) {
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	ans = cost[right];
	printf("%d", ans);
	return 0;
}