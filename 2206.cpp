#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

#define INF 987654321
using namespace std;

vector<vector<int>>input;
int dp[1001][1001][2];
int dr[] = { 0,0, -1,1 };
int dc[] = { 1,-1, 0,0 };
int n, m;

int bfs(int r, int c, int cnt) {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,cnt},{r,c} });
	int ret = INF;
	dp[0][0][1] = 0;
	dp[0][0][0] = 0;
	while (!q.empty()) {
		pair<int, int> pos = q.front().second;
		int count = q.front().first.second;
		int cost = q.front().first.first + 1;
		q.pop();
		if (pos.first == n - 1 && pos.second == m - 1) {
			ret = min(ret, cost);
		}
		
		else {
			for (int i = 0; i < 4; i++) {
				int tr = pos.first + dr[i];
				int tc = pos.second + dc[i];

				if (tr >= 0 && tr < n &&tc >= 0 && tc < m) {
					if (input[tr][tc] == 1 && count == 0 && dp[tr][tc][1]>cost) {
						q.push({ { cost,1 },{ tr,tc } });
						dp[tr][tc][1] = cost;
					}
					if (input[tr][tc] == 0 && dp[tr][tc][count]>cost) {
						q.push({ { cost ,count },{ tr,tc } });
						dp[tr][tc][count] = cost ;
					}
				}
			}
		}
	}
	return ret;
}


int main() {
	int tmp;
	scanf("%d %d", &n, &m);
	input.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j][0] = INF;
			dp[i][j][1] = INF;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &tmp);
			input[i].push_back(tmp);
		}
	}

	int ans = bfs(0, 0,0);
	if (ans == INF)
		printf("%d", -1);
	else
		printf("%d", ans);
	return 0;
}