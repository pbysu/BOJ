#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int n;
int num[1001];
int dp[1001];
int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 2; i <= n; i++) {
		dp[i] = INF;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= i+num[i]; j++) {
			dp[j] = min(1 + dp[i], dp[j]);
		}
	}
	if (dp[n] == INF) dp[n] = -1;
	printf("%d", dp[n]);
	return 0;
}