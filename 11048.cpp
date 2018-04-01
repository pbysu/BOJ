#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n, m;
int input[1000][1000];
int dp[1000][1000];

int dr[3] = { 1, 1,0 };
int dc[3] = { 0, 1 ,1};

int func(int r, int c) {
	if (r==n-1 && c==m-1)
		return 0;
	int &ret = dp[r][c];
	if (ret != -1) return ret;
	ret = -1;


	int ny = r + 1;
	int nx = c + 1;

	if (ny <n)
		ret = max(ret, func(r + 1, c) + input[r + 1][c]);
	if (nx < m)
		ret = max(ret, func(r, c + 1) + input[r][c + 1]);
	if (ny < n && nx < m)
		ret = max(ret, func(r + 1, c + 1) + input[r + 1][c + 1]);

	return ret;
}
int main() {
	scanf("%d %d", &n, &m);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &input[i][j]);
		}
	}
	printf("%d", func(0, 0)+input[0][0]);
	return 0;
}