#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define mod 1000000
using namespace std;
int n;
int dp[1010][2][3];
int func(int pos, int tardy, int absent) {
	if (pos == n) return 1;
	int &ret = dp[pos][tardy][absent];
	if (ret != -1)
		return ret;
	ret = 0;
	if (tardy < 1)
		ret = (ret + func(pos + 1, tardy + 1, 0)) % mod;
	if (absent < 2)
		ret = (ret + func(pos + 1, tardy, absent + 1)) % mod;
	ret = (ret + func(pos + 1, tardy, 0)) % mod;
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	printf("%d", func(0, 0, 0));
	return 0;
}