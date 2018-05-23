#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int n;
int input[100][100];
int visited[100][100];
int dp[100][100];
int regin[100][100];
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0 , 0 };
int MIN = 987654321;
queue<pair<int, int>> qa;

int k = -1;

void bfs(int r, int c) {
	int ttr, ttc, tr, tc;
	queue<pair<int, pair<int, int>>>q;
	int sizeq;
	q.push({ input[r][c] ,{ r,c } });
	
	
	int start;

	while (!q.empty()) {
		tr = q.front().second.first;
		tc = q.front().second.second;
		start = q.front().first;
		
		q.pop();

		for (int i = 0; i < 4; i++) {
			ttr = tr + dr[i];
			ttc = tc + dc[i];

			if (ttr < 0 || ttr >= n || ttc < 0 || ttc >= n)
				continue;

			if (input[tr][tc]==0 && input[ttr][ttc]<0 && input[ttr][ttc] != start &&MIN>dp[tr][tc] ) {
				MIN = dp[tr][tc];
			}

			if (input[ttr][ttc] == 0 && dp[ttr][ttc] > dp[tr][tc] + 1) {
				dp[ttr][ttc] = dp[tr][tc] + 1;
				q.push({ start,{ ttr,ttc } });
			}


		}
	}
}

void rbfs(int r, int c) {

	int ttr, ttc, tr, tc;
	queue<pair<int, int>>q;
	int sizeq;
	q.push({ r,c });
	visited[r][c] = true;
	input[r][c] = k;

	while (!q.empty()) {
		tr = q.front().first;
		tc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			ttr = tr + dr[i];
			ttc = tc + dc[i];

			if (ttr < 0 || ttr >= n || ttc < 0 || ttc >= n)
				continue;

			if (input[ttr][ttc] == 0) {
				qa.push({ tr,tc });
			}

			if (input[ttr][ttc] == 1 && !visited[ttr][ttc]) {
				visited[ttr][ttc] = true;
				input[ttr][ttc] = k;
				q.push({ ttr,ttc });
			}
		}
	}
}


int main() {
	scanf("%d", &n);
	memset(dp, 0x7f, sizeof(dp));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &input[i][j]);
		}
	}

	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (input[i][j] == 1&&!visited[i][j]) {
				rbfs(i, j);
				k--;
			}
		}
	}
	int sizeqa = qa.size();
	int temp = -1;
	int tr, tc;

	while (sizeqa--) {
		tr = qa.front().first;
		tc = qa.front().second;
		qa.pop();
		if (temp != input[tr][tc]) {
			temp = input[tr][tc];
			memset(dp, 0x7f, sizeof(dp));
		}

		if (dp[tr][tc] == 0)
			continue;

			dp[tr][tc] = 0;
			bfs(tr, tc);
			
	}

	printf("%d", MIN);

	return 0;
}