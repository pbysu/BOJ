#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
int input[2][100001];
int dp[2][100001];

int func(int r, int c) {
	if (c >= n) return 0;
	int &ret = dp[r][c];
	if (ret != 0) return ret;

	if (r == 0) {
		ret = input[r][c] + max(func(r + 1, c + 1), func(r + 1, c + 2));
	}
	if (r == 1) {
		ret = input[r][c] + max(func(r - 1, c + 1), func(r - 1, c + 2));
	}
	return ret;
}
int main() {
	int tc;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &input[i][j]);
			}
		}
		printf("%d\n", max(func(0, 0), func(1, 0)));
		memset(dp, 0, sizeof(dp));
	}



	return 0;
}