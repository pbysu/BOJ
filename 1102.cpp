#include<iostream>
#include<algorithm>
#include<vector>
#define INF 1000000000
using namespace std;
int n, yorn, cnt;
int cost[16][16];
vector<int> dp;
char a;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%1c", &a);
		if (a == 'Y') {
			yorn += (1 << i);
		}
	}
	scanf("%d", &cnt);
	int ret = INF;
	dp.resize(1 << n, INF);
	dp[yorn] = 0;
	for (int i = yorn; i < (1 << n); i++) {
		if (dp[i] == INF) continue;
		for (int j = 0; j < n; j++) {
			if (i&(1 << j)) {
				for (int k = 0; k < n; k++) {
					if (!(i&(1 << k))) {
						if (dp[i | (1 << k)] == INF || dp[i | (1 << k)] > dp[i] + cost[j][k]) {
							dp[i | (1 << k)] = dp[i] + cost[j][k];
						}
					}
				}
			}
		}
	}
	int tmp;
	for (int i =yorn; i < (1 << n); i++) {
		if (dp[i] == INF)continue;
		tmp = 0;
		for (int j = 0; j < n; j++) {
			if ((i&(1 << j))) {
				tmp++;
				if (tmp == cnt)
					break;
			}
		}
		if(tmp==cnt)
			ret = min(dp[i], ret);
	}
	if (ret == INF)
		ret = -1;
	printf("%d\n", ret);
	return 0;
}