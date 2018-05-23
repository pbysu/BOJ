#include<iostream>
#include<algorithm>

using namespace std;

int dr[] = { 0,1 };
int dc[] = { 1, 0 };

int n, m, k;
int mr, mc;
int input[20][20];
int dp[20][20];

int func(int r, int c) {
	
	int &ret = dp[r][c];
	if (r == n && m == c) return ret= 1;
	if (mr + mc == r + c && mr!= r && mc!= c ) return ret = 0;
	if (ret != 0) return ret;
	int tr, tc;
	for (int i = 0; i < 2; i++) {
		tr = dr[i] + r;
		tc = dc[i] + c;
		if (tr > 0 && tr <= n && tc > 0 && tc <= m ) {
			ret += func(tr, tc);
		}
	}
	return ret;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	int tmp = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			input[i][j] = tmp;
			if (tmp == k) {
				mr = i;
				mc = j;
			}
			tmp++;
		}
	}

	printf("%d", func(1, 1));

	return 0;
}