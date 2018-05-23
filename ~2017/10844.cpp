#include<algorithm>
#include<iostream>
#define mod 1000000000
using namespace std;
typedef unsigned long long ll;


ll dp[101][11];

int main() {
	int n;
	scanf("%d", &n);
	ll ans = 0;
	for (int i = 1; i < 10; i++) {
		dp[0][i] = 1;
	}
	
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j < 9; j++) {
			dp[i][j] = (dp[i - 1][j + 1] + dp[i][j]) % mod;
			dp[i][j] = (dp[i - 1][j - 1] + dp[i][j]) % mod;
		}
		dp[i][9] = dp[i - 1][8];
	}

	for (int i = 0; i < 10; i++) {
		ans = (dp[n - 1][i] + ans) % mod;
	}

	printf("%llu", ans);
	return 0;
}