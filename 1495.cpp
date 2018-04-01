#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 987654321
using namespace std;
int dp[101][1001];
int val[101];
int n, s, m;

int func(int pos, int cost) {
	if (pos == n+1)return cost;
	int &ret = dp[pos][cost];
	if (ret != -1) return dp[pos][cost];
	ret = -INF;
	if (cost + val[pos] <= m)
		ret = max(func(pos + 1, cost + val[pos]), ret);
	if (cost - val[pos] >= 0)
		ret = max(ret, func(pos + 1, cost - val[pos]));
	return ret;
}
int main() {
	scanf("%d %d %d", &n, &s, &m);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
	int ans = func(1, s);
	if (ans == -INF)
		ans = -1;
	printf("%d", ans);
	return 0;
}