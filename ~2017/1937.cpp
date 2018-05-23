#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1,0,0 };
int input[502][502];
int dp[501][501];
int ans = 0;
int func(int r, int c) {
	int temp = 0;
	int &ret = dp[r][c];
	if (dp[r][c] != 0)
		return dp[r][c];
	else
		ret = 1;

	for (int i = 0; i < 4; i++) {
		
		if (input[r][c] < input[r + dx[i]][c + dy[i]]) {
			
			temp = max(func(r + dx[i], c + dy[i]),temp);


		}
	}
	ret += temp;

	return ret;
}


int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &input[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans = max(func(i, j), ans);
		}
	}

	printf("%d", ans);
	return 0;
}