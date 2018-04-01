#include<iostream>
#include<algorithm>
#define INF 987654321
using namespace std;
typedef long long ll;
int n, table[100010][3], k = 0;
int dp[100010][3];
pair<int, int> ret = { 0,INF };

int func(int r, int c) {
	if (r == n - 1 && c == 1)
		return table[r][c];
	if (r == n) return INF;

	int &ret = dp[r][c];
	if (ret != INF)
		return ret;
	ret = table[r][c];

	int temp = INF;
	if (c == 0) {
		temp = min(func(r, 1), min(func(r + 1, 0), func(r + 1, 1)));
	}
	else if (c == 1) {
		temp = min(func(r + 1, 0), min(func(r + 1, 1), min(func(r + 1, 2), func(r, 2))));
	}
	else {
		temp = min(func(r + 1, 2), func(r + 1, 1));
	}
	return ret = ret + temp;
}
int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;
		k++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][j] = INF;
				scanf("%d", &table[i][j]);
			}
		}

		int tmp = func(0, 1);
		printf("%d. %d\n", k, tmp);
	}

	return 0;
}