#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define INF 60
using namespace std;
vector<vector<int>> v;
int dp[102][22];

int main() {
	int n, t;
	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 22; j++) {
			dp[i][j] = INF;
		}
	}

	scanf("%d\n%d", &n, &t);
	v.resize(n + 1);

	int m, tmp;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &tmp);
			v[i].push_back(tmp);
		}
	}

	v[0].push_back(1);
	dp[0][1] = 0;

	int h, ex;
	int cmp;

	for (int i = 0; i <= n; i++) {
		if (i==0) cmp = 0;
		else cmp = ex;

		ex = INF;

		for (int j = 0; j < v[i].size(); j++) {
			h = v[i][j];

			if (dp[i][h] == INF) {
				if (cmp < t) dp[i][h] = cmp + 1;

				else continue;
			}

			dp[i + 1][h] = min(dp[i][h], dp[i + 1][h]);

			if (h + 1 < 21)
				dp[i + 1][h + 1] = min(dp[i][h], dp[i + 1][h + 1]);

			if (h - 1 > 0)
				dp[i + 1][h - 1] = min(dp[i][h], dp[i + 1][h - 1]);

			if (h < 10)
				dp[i + 1][h * 2] = min(dp[i][h], dp[i + 1][h * 2]);

			else dp[i + 1][20] = min(dp[i][h], dp[i + 1][20]);

			ex = min(ex, dp[i][h]);
		}
	}

	int ans = INF;

	for (int i = 0; i < v[n].size(); i++) {
		ans = min(ans, dp[n][v[n][i]]);
	}

	printf("%d\n", ans == INF ? -1 : ans);

	return 0;
}