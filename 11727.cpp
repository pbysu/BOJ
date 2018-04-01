#include<iostream>
#include<algorithm>
#define mod 10007
using namespace std;

int dp[1001];
int n;
int func(int c) {
	if (n < c) return 0;
	if (n == c) return 1;
	int &ret = dp[c];
	if (ret != 0) return ret;

	ret = (func(c + 1) + 2*func(c + 2)) % mod;

	return ret;
}
int main() {

	scanf("%d", &n);

	printf("%d", func(0));
	return 0;
}