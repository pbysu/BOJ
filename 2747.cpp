#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int num;
int dp[50];
int func(int n) {
	int &ret = dp[n];
	if (ret != -1)
		return ret;
	ret = 0;
	return ret = func(n - 2) + func(n - 1);
}
int main() {
	scanf("%d", &num);
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	printf("%d", func(num));

	return 0;
}