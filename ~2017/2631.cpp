#include<stdio.h>
#include<algorithm>
using namespace std;
int n, dp[200], sz;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, pos;
		scanf("%d", &a);
		pos = lower_bound(dp, dp + sz, a) - dp;
		dp[pos] = a;
		if (pos == sz) sz++;
	}
	printf("%d", n - sz);
	return 0;
}