#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
typedef pair<int, int> pii;
vector<pii> v;
int dp[1010][1010];
int par[1010];
inline int dis(int idx, int cur) {
	return abs(v[idx].first - v[cur].first)
		+ abs(v[idx].second - v[cur].second);
}
int func(int cur, int a, int b) {
	if (cur == m)return 0;
	int &ret = dp[a][b];
	if (ret != -1)return ret;
	ret = 0;
	return ret = min(func(cur + 1, cur, b) + dis(a, cur),func(cur + 1, a, cur) + dis(b, cur));
}
void back(int cur,int val, int a, int b) {
	if (cur == m) return;
	if (val == dis(a, cur) + func(cur + 1, cur, b))
		par[cur] = 1, back(cur + 1, val - dis( cur, a), cur, b);
	else
		par[cur] = 2, back(cur + 1, val - dis(cur ,b), a, cur);
}
int main() { 
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n,&m	);
	v.resize(n+2);
	v[0] = { 1, 1};
	v[1] = { n, n };
	m += 2;
	for (int i = 2; i < m; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}
	int a = 0, b = 1;
	int ans = func(2, 0, 1);
	back(2, ans, 0, 1);
	printf("%d\n", ans);
	for (int i = 2; i < m; i++)
		printf("%d\n", par[i]);
	return 0;
}