#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
int n, m, tmp;
vector<pair<int,int>> height;
typedef pair<int, int> pii;
vector<vector<int>> adj;
vector<int> dp;
vector<int> ans;
int func(int pos) {
	int &ret = dp[pos];
	ret = 0;
	for(int next : adj[pos]){
		ret = max(ret, dp[next]);
	}
	return ret += 1;
}
int main() {
	scanf("%d%d", &n, &m);
	height.resize(n);
	adj.resize(n);
	ans.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &height[i].first);
		height[i].second = i;
	}
	for (int u,v, i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		u--, v--;
		if (height[u] > height[v]) swap(u, v);
		adj[u].push_back(v);
	}
	sort(height.begin(), height.end(), [](pii p, pii q) {return p.first > q.first; });
	int pos;
	for (int i = 0; i < n; i++) {
		pos = height[i].second;
		ans[pos] = func(pos);
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}