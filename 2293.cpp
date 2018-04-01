#include<iostream>
#include<algorithm>
using namespace std;
int weight[100];
int dp[10001];
int n, k;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n;i++) {
		scanf("%d", &weight[i]);
	}
	dp[0] = 1;
	for (int i = 0; i < n;i++) {
		for (int j = weight[i]; j <= k; j++) {
			dp[j] += dp[j -weight[i]];
		}
	}

	printf("%d", dp[k]);
	return 0;
}