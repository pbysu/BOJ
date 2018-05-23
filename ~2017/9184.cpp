#include <iostream>
#include <algorithm>

using namespace std;

int dp[21][21][21];

int w(int a, int b, int c) {

	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}

	else if ((a > 20 || b > 20 || c > 20)) {
		return w(20, 20, 20);
	}

	else if (dp[a][b][c] != 0)
		return dp[a][b][c];

	else if (a < b && b < c) {
		dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return dp[a][b][c];
	}

	else {
		dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c)
			+ w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
		return dp[a][b][c];
	}
}

int main() {
	int x, y, z;
	int tx, ty, tz;
	while (true) {
		scanf("%d %d %d", &x, &y, &z);
		if (x == -1 && y == -1 && z == -1) {
			break;
		}
		printf("w(%d, %d, %d) = %d\n", x, y, z, w(x, y, z));
	}
	return 0;
}