#include<iostream>
#include<algorithm>

using namespace std;
int n[1010];
int dp[1010];
int MAX = 0;
int main() {

	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d", &n[i]);
		dp[i] = 1;
	}
	
	for (int i = 1; i < tc; i++) {
		for (int j = 0; j < i; j++) {
			if (n[i] > n[j] && dp[i] < dp[j]+1) {
				dp[i] = dp[j] + 1;
			}
		}
		MAX = max(MAX, dp[i]);
	}
	printf("%d", MAX);
	return 0;
}