#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define INF 1e9
using namespace std;
int in[50001], dp[50001][3];
int n, k;

int func(int pos, int idx) {
	if (idx == 3)return 0;
	if (pos > n) return -INF;
	int &ret = dp[pos][idx];
	if (ret != -1)return ret;
	ret = max((idx <= 3 && pos+k<=n ? func(pos + k, idx + 1) + in[pos + k] - in[pos] : 0),
		pos+1 <= n ?func(pos+1,idx): 0);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int tmp, i = 1; i <= n; i++) {
		scanf("%d", &in[i]);
		in[i] += in[i - 1];
	}
	scanf("%d", &k);
	printf("%d\n", func(0, 0));
	return 0;
}