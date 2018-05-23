#include<iostream>
#include<algorithm>
#include<cstring>
#define mod 10007
using namespace std;
int dp[1001][10];
int n;
int func(int len, int pos) {
	if (len == n)
		return 1;
	int &ret = dp[len][pos];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = pos; i <=9; i++) {
		ret =(ret+ func(len + 1,i))%mod;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%d", func(0, 0));

	return 0;
}