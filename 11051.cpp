#include<iostream>
#include <algorithm>

using namespace std;
int n, c;
int dp[1002][1001];
int main() {
	scanf("%d %d", &n, &c);
	if (n - c < c) c = n - c;
	dp[1][0] = 1;
	for (int i = 2; i <= n+1; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}


	printf("%d", dp[n+1][c]);
	return 0;
}