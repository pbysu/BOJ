#include<iostream>
#include<algorithm>

using namespace std;
int num[1010];
int dp[1010];
int n;
int MAX = 0;

void func(int pos,int mul) {
	for (int i = pos+1; i < n; i++) {
		if (dp[i] - dp[pos] * mul > dp[pos]*mul) break;

		if (dp[i] - dp[pos]*mul == dp[pos]) {
			if (i == n - 1) {
				 MAX = max(MAX, dp[pos]);
				 return;
			}
			else {
				mul++;
			}
		}
	}
	if(pos+1<n)	func(pos + 1, mul);
	if (pos == n - 1 && MAX == 0) MAX = dp[pos];
}
int main() {	

	int tc;
	int sum;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		scanf("%d", &n);
		MAX = 0;
		sum = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d", &num[j]);
			sum += num[j];
			dp[j] = sum;
		}
		func(0, 1);

		printf("%d\n", MAX);
	}

	
	return 0;
}