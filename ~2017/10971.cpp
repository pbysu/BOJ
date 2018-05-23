#include<iostream>
#include<algorithm>
#include<vector>
#define INF 987654321
using namespace std;
int table[11][11];
int n;
vector<vector<int>> dp;

int func(int pos, int ex,int s) {
	if (pos == (1 << n) - 1)
		return table[ex][s];

	int &ret = dp[pos][ex];
	
	for (int i = 0; i < n; i++) {
		if ((pos&(1<<i)) == 0&&table[ex][i])
			ret = min(ret, func((pos | 1<<i), i,s) + table[ex][i]);
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &table[i][j]);
		}
	}
	int ans = INF;
	dp.resize((1 << (n)), vector<int>(n, INF));
	ans = func(1 << 0, 0, 0);
	printf("%d", ans);



	return 0;
}