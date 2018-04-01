#include<iostream>

using namespace std;
long long dp[101][101][101];

int main() {
	int R, L, N;

	scanf("%d %d %d", &N, &R, &L);
	dp[1][1][1] = 1;
	dp[2][2][1] = dp[2][1][2] = 1;

	for (int n = 3; n <= N; n++) {
		dp[n][n][1] = dp[n][1][n] = 1;
		for (int l = 1; l <= n; l++) {
			for (int r = 1; r <= n; r++) {
				dp[n][l][r] = (
					(
					(dp[n - 1][l][r] * (n - 2)) % 1000000007 
					+ dp[n - 1][l - 1][r]) % 1000000007 
					+ dp[n - 1][l][r - 1]) % 1000000007;
			}
		}
	}

	printf("%lld\n", dp[N][L][R]);

	return 0;
}