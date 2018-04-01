#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef unsigned long long ull;

ull dp[92];
int n;

ull func(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	ull &ret = dp[n];
	if (dp[n] != 0)
		return ret;

	return ret = func(n - 1) + func(n - 2);
}
int main() {
	scanf("%d", &n);
	
	printf("%llu\n",func(n));

	return 0;
}