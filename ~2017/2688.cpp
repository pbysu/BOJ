#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef unsigned long long ull;
ull dp[65][10];
int t, n;
ull func(int pos, int num) {
	ull &ret = dp[pos][num];
	if (ret != 0) {
		return ret;
	}
	if (pos == 0)
		return ret = 1;
	ret = 0;
	for (int i = 0; i <= num; i++) {
		ret += func(pos - 1, i);
	}
	return ret;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%llu\n", func(n, 9));
	}
	return 0;
}