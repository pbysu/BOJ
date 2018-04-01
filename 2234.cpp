#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>	
#include<stack>
using namespace std;
int n, m, table[51][51], totalRoom = 1, oRoom = 0, tRoom = 0, dp[51][51];
bool check[51][51];
int areaIdx = 0;
int dr[4] = { 0,-1, 0, 1 };
int dc[4] = { -1, 0, 1, 0 };
int ex = 0;
vector<int> area;
vector<queue<pair<int, int>>> q(2501);
int func(int r, int c, bool isItStart) {
	if (dp[r][c] != 0) return area[dp[r][c]-1];
	dp[r][c] = totalRoom;
	int tmp = 0;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int tr = r + dr[i];
		int tc = c + dc[i];
		if (tr >= 0 && tr < n && tc >= 0 && tc < m && !dp[tr][tc]) {
			if ((table[r][c] & (1 << i)) == 0) {
				ret += func(tr, tc, false);
			}
			else if (!check[tr][tc]) {
				check[tr][tc] = true;
				q[totalRoom].push({ tr, tc });
			}
		}
	}
	if (isItStart) {
		totalRoom++;
		area.push_back(ret);
		oRoom = max(oRoom, ret);
	}
	return ret;
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &table[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
		
				int ret = func(i, j, true);
				int tmp = 0;
				int siz = q[dp[i][j]].size() - ex;
				while(!q[dp[i][j]].empty()){
					if (dp[q[dp[i][j]].front().first][q[dp[i][j]].front().second] != dp[i][j])
						tmp = max(tmp, func(q[dp[i][j]].front().first, q[dp[i][j]].front().second, true));
					q[dp[i][j]].pop();
				}
				tRoom = max(tRoom, ret + tmp);
		}
	}

	printf("%d\n%d\n%d\n", totalRoom - 1, oRoom, tRoom);

	return 0;
}