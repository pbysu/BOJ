#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 987654321
using namespace std;
int t, n, w;
int dp[4][10010][4];
int table[2][10010];
int func(int statue, int pos, int first) {
	int &ret = dp[statue][pos][first];
	if (ret != -1)
		return ret;
	ret = INF;
	if (pos == n) {
		int cnt = 0;
		if (statue == 3) {
			if (first == 0) {
				return ret = 2;
			}
			else if (first == 3) {
				return ret = 0;
			}
			else
				return ret = 1;
		}
		else if (statue == 0) {
			cnt = 0;
			if (n == 1) {
				ret = 2;
				if (table[0][1] + table[1][1] <= w)
					ret = 1;
				return ret;
			}
			if (first == 0) {
				if (table[0][n] + table[0][1] <= w)
					cnt++;
				if (table[1][n] + table[1][1] <= w)
					cnt++;
				return ret = 4 - cnt;
			}
			else if (first == 1) {
				if (table[1][1] + table[1][n] <= w) {
					cnt++;
				}
				return ret = 3 - cnt;
			}
			else if (first == 2) {
				if (table[0][1] + table[0][n] <= w) {
					cnt++;
				}
				return ret = 3 - cnt;
			}
			else if (first == 3) {
				if (table[0][n] + table[1][n] <= w)
					return ret = 1;
				return ret = 2;
			}
		}
		else if (statue == 1) {
			cnt = 0;
			if (table[1][n] + table[1][1] <= w)
				cnt++;
			if (first == 0) {
				return ret = 3 - cnt;
			}
			else if (first == 1) {
				return ret = 2 - cnt;
			}
			else if (first == 2) {
				return ret = 2;
			}
			else if (first == 3) {
				return 1;
			}
		}
		else if (statue == 2) {
			cnt = 0;
			if (table[0][n] + table[0][1] <= w)
				cnt++;
			if (first == 0) {
				return ret = 3 - cnt;
			}
			else if (first == 2) {
				return ret = 2 - cnt;
			}
			else if (first == 1) {
				return ret = 2;
			}
			else if (first == 3) {
				return ret = 1;
			}
		}
		return ret;
	}

	if (pos == 1) {
		if (table[0][pos] + table[1][pos] <= w) {
			ret = min(func(0, pos + 1, 3) + 1, ret);
		}
		ret = min(func(0, pos + 1, 0), ret);

		if (table[0][pos] + table[0][pos + 1] <= w && table[1][pos] + table[1][pos + 1] <= w) {

			ret = min(func(3, pos + 1, 3) + 2, ret);
		}

		if (table[0][pos] + table[0][pos + 1] <= w) {

			ret = min(func(1, pos + 1, 1) + 1, ret);

		}
		if (table[1][pos] + table[1][pos + 1] <= w) {

			ret = min(ret, func(2, pos + 1, 2) + 1);

		}
		return ret;
	}

	else {
		if (statue == 0) {
			if (table[0][pos] + table[1][pos] <= w)
				ret = func(0, pos + 1, first) + 1;
			else
				ret = func(0, pos + 1, first) + 2;

			if (table[0][pos] + table[0][pos + 1] <= w && table[1][pos] + table[1][pos + 1] <= w)
				ret = min(func(3, pos + 1, first) + 2, ret);

			if (table[0][pos] + table[0][pos + 1] <= w)
				ret = min(func(1, pos + 1, first) + 2, ret);

			if (table[1][pos] + table[1][pos + 1] <= w)
				ret = min(ret, func(2, pos + 1, first) + 2);


		}
		else if (statue == 1) {
			if (table[1][pos] + table[1][pos + 1] <= w)
				ret = min(ret, func(2, pos + 1, first) + 1);
			ret = min(ret, func(0, pos + 1, first) + 1);
		}
		else if (statue == 2) {
			if (table[0][pos] + table[0][pos + 1] <= w)
				ret = min(ret, func(1, pos + 1, first) + 1);
			ret = min(func(0, pos + 1, first) + 1, ret);
		}
		else if (statue == 3) {
			return func(0, pos + 1, first);
		}
	}
	return ret;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &w);
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &table[i][j]);
			}
		}
		memset(dp, -1, sizeof(dp));
		int ret = func(0, 1, 0);
		ret = min(ret, n * 2);
		printf("%d\n", ret);
	}
	return 0;
}