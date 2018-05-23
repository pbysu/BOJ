#include<iostream>
#include<algorithm>

using namespace std;

int input[310][310];
int dp[310][310];

int main() {
	int n, m, tmp;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d ", &input[i][j]);
			dp[i][j] = input[i][j] + dp[i][j - 1];
		}
	}
	scanf("%d", &tmp);

	int sr, sc, er, ec;
	while (tmp--) {
		scanf("%d %d %d %d", &sr, &sc, &er, &ec);

		if (sr > er)
			swap(sr, er);
		if (sc > ec)
			swap(sc, ec);
		int ans = 0;
		for (int i = sr; i <= er; i++) {
			ans += dp[i][ec] - dp[i][sc - 1];
		}

		printf("%d\n", ans);
	}

	return 0;
}