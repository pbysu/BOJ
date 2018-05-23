#include <cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, k, in[500][2], dp[501][501];
int dist(int u, int v) {
	return abs(in[u][0] - in[v][0]) + abs(in[u][1] - in[v][1]);
}

int func(int cur, int rem) {
	if (cur == n-1)return 0;
	int &ret = dp[cur][rem];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 0; i <= rem; i++) {
		if (cur + 1 + i >= n)break;
		ret  =min(ret, func(cur + 1 + i, rem - i) + dist(cur, cur + 1 + i));
	}
	return ret;
}
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &in[i][0], &in[i][1]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d", func(0, k));
	return 0;
}