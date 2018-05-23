#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;


int n, m;

queue<pair<int, int>> qW;
char input[50][50];
int dp[50][50];
bool visited[50][50];
int dr[] = { 0 , 0, -1, 1 };
int dc[] = { 1, -1, 0, 0 };

pair<int, int> s;
pair<int, int> e;


void bfs(pair<int, int> pos) {

	int r = pos.first;
	int c = pos.second;
	visited[r][c] = true;
	queue<pair<int, int>> qbfs;
	int tr, tc;
	qbfs.push({ r,c });
	int sizeq;
	int ttr, ttc;
	int check = 0;
	dp[r][c] = check;
	check++;

	while (!qbfs.empty()) {
		sizeq = qbfs.size();

		while (sizeq--) {
			tr = qbfs.front().first;
			tc = qbfs.front().second;
			qbfs.pop();

			for (int i = 0; i < 4; i++) {
				ttr = tr + dr[i];
				ttc = tc + dc[i];
				if (ttr<0 || ttr>n || ttc<0 || ttc>m) continue;
				if (input[ttr][ttc] == '.' && !visited[ttr][ttc]) {
					visited[ttr][ttc] = true;

					if (check < dp[ttr][ttc]) {
						dp[ttr][ttc] = check;
						qbfs.push({ ttr, ttc });
					}
					else continue;
				}
			}
		}
		check++;

	}
}

int find(int r, int c) {
	queue<pair<int, int> > qf;

	qf.push({ r,c });
	int tr, tc, ttr, ttc;
	int ret = 1;

	while (!qf.empty()) {
		int sizeqf = qf.size();

		while (sizeqf--) {
			tr = qf.front().first;
			tc = qf.front().second;
			qf.pop();

			for (int i = 0; i < 4; i++) {
				ttr = tr + dr[i];
				ttc = tc + dc[i];
				if (ttr<0 || ttr>n || ttc<0 || ttc>m) continue;

				if (input[ttr][ttc] == 'D')
					return ret;

				if (!visited[ttr][ttc] && input[ttr][ttc] == '.'
					&& dp[ttr][ttc]>ret) {
					qf.push({ ttr,ttc });

					visited[ttr][ttc] = true;
				}

			}

		}
		ret++;
	}

	return -1;
}


int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = 987654321;
		}
	}
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &input[i][j]);
			if (input[i][j] == '*')
				qW.push({ i,j });
			else if (input[i][j] == 'S')
				s = { i,j };
		}
		getchar();
	}

	int sizew = qW.size();

	while (sizew--) {
		bfs(qW.front());
		qW.pop();

		memset(visited, false, sizeof(visited));
	}
	int ans = find(s.first, s.second);

	if (ans == -1) {
		printf("KAKTUS");
	}

	else
		printf("%d", ans);

	return 0;
}