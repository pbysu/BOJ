#include<iostream>
#include<cstring>
#include<algorithm>
#define mod 15746
using namespace std;

int dp[1000000];
int n;
int func(int len) {
	if (len > n)
		return 0;
	if (len == n)
		return 1;
	int& ret = dp[len];
	if (ret != -1) return ret;
	ret = 0;

	ret = (ret + func(len + 2)) % mod;
	ret = (ret + func(len + 1)) % mod;

	return ret;
}
int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%d", func(0));
}