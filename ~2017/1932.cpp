#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int input[505][505];
int dp[505][505];

int func(int y, int x, int n) {

	if (y == n) return input[y][x];
	int &ret = dp[y][x];
	if (ret != -1)	 return ret;

	ret++;

	ret += max(func(y+1, x, n), func(y+ 1, x + 1, n)) + input[y][x];

	return ret;
}


int main() {
	int n;
	scanf("%d ", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &input[i][j]);
		}
	}

	printf("%d", func(1, 1, n));


	return 0;
}