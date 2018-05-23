#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int sum[101][1001];
pair<int, int> input[101];
int n, m, k;
int a, b;
int dp[101][10001];

int func(int r, int val) {
	if (val == n) return 1;
	if (val>n || r > m) return 0;

	int &ret = dp[r][val];
	if (ret != -1) return ret;
	else ret = 0;
	for (int i = 0; i <= input[r].second; i++) {
		ret +=func(r+1,val +sum[r][i]);
	}
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		input[i].first = a;
		input[i].second = b;
		for (int j = 0; j <=b; j++) {
			sum[i][j] = a*j;
		}
	}

	int ans = 0;
	for (int i = 0; i <= input[0].second; i++) {
		ans += func(1,sum[0][i]);
	}
	printf("%d", ans);
	

	return 0;
}