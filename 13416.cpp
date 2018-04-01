#include<iostream>
#include<algorithm>

using namespace std;
int input[3][1000];
int dp[1000];
int main() {
	int tc, n;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &input[0][i], &input[1][i], &input[2][i]);
		}
		dp[0] = max(input[0][0], max(input[1][0], max(input[2][0], 0)));
		for (int i = 1; i < n; i++) {
			dp[i] = dp[i-1]+ max(input[0][i], max(input[1][i], max(input[2][i], 0)));
		}
		printf("%d\n", dp[n - 1]);
	}

	return 0;
}