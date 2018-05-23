#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;;
int n, m;
int table[510][510];
ll dp[510][510];
bool check[510][510];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1, 0, 0 };

ll func(int r, int c) {
	ll &ret = dp[r][c];
	if (ret != -1)return ret;	
	if (r == n - 1 && c == m - 1) return 1;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int tr = r + dr[i];
		int tc = c + dc[i];
		if (tr >= 0 && tr < n && tc >= 0 && tc < m && table[tr][tc] < table[r][c]) {
			ret +=func(tr, tc);
		}
	}
	return ret;
}
int main() {
	scanf("%d %d", &n, &m);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &table[i][j]);
		}
	}
	printf("%d", func(0, 0));


	return 0;
}