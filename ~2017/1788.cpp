#include<iostream>
#include<algorithm>
#include<vector>
#define mod 1000000000
#define INF 987654321
using namespace std;
int n;
vector<int> dp;
int func(int num) {
	int &ret = dp[num];
	if (ret != -INF)
		return ret;
	if (num == 0)
		return ret = 0;
	if (num == 1)
		return ret = 1;
	ret = (func(num - 1) % mod + func(num - 2) % mod) % mod;
	return ret;

}
int main() {
	scanf("%d", &n);
	dp.resize(abs(n)+1,-INF);
	dp[0] = 0;
	dp[1] = 1;
	if (n >= 0) {
		int tmp = func(n);
		if (n==0)
			printf("%d\n%d", 0, 0);
		else
			printf("%d\n%d", 1, tmp);
	}
	else {
		int ab = abs(n);
		int tmp = func(abs(n));
		if (!(abs(n) % 2))
			printf("-1\n%d", tmp);
		else
			printf("1\n%d", tmp);
	}
	return 0;
}