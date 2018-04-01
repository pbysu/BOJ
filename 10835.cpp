#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n;
int a[2002];
int b[2002];
int dp[2002][2002];

int func(int aidx, int bidx) {
	if (aidx == n || bidx == n)
		return 0;
	int&ret = dp[aidx][bidx];
	if (ret != -1)return ret;
	ret = 0;
	if (bidx <n && aidx <n && a[aidx] > b[bidx])
		ret = max(func(aidx, bidx+1) + b[bidx], ret);
	if (aidx <n) {
		ret = max(func(aidx +1, bidx), ret);

		if (bidx < n) {
			ret = max(func(aidx +1, bidx +1), ret);
		}

	}
	return ret;
}
int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	printf("%d", func(0, 0));

	return 0;
}