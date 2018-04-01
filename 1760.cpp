#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAX 10000
using namespace std;
bool visited[MAX], flage, ex;
int N, M, rCnt, cCnt, rTable[100][100], cTable[100][100], table[100][100];
vector<vector<int>> adj;
vector<int> row, col;
vector<vector<bool>>check;
int dfs(int pos) {
	visited[pos] = true;
	for (int next : adj[pos]) {
		if (!col[next] || !visited[col[next]] && dfs(col[next])) {
			col[next] = pos;
			row[pos] = next;
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &table[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		flage = false;
		ex = false;
		for (int j = 0; j < M; j++) {
			if (ex && table[i][j] == 1) flage = true;
			else if (table[i][j] == 2) flage = false, ex = false;
			else if (table[i][j] == 0) {
				ex = true;
				if (j == 0) rTable[i][j] = ++rCnt;
				else {
					if (flage) rTable[i][j] = rCnt;
					else if (table[i][j - 1] == 0) rTable[i][j] = rTable[i][j - 1];
					else rTable[i][j] = ++rCnt;
				}
			}
		}
	}

	for (int j = 0; j < M; j++) {
		flage = false;
		ex = false;
		for (int i = 0; i < N; i++) {
			if (ex && table[i][j] == 1) flage = true;
			else if (table[i][j] == 2) ex = false, flage = false;
			else if (table[i][j] == 0) {
				ex = true;
				if (i == 0) cTable[i][j] = ++cCnt;
				else {
					if (flage) cTable[i][j] = cCnt;
					else if (table[i - 1][j] == 0) cTable[i][j] = cTable[i - 1][j];
					else cTable[i][j] = ++cCnt;
				}
			}
		}
	}
	rCnt++, cCnt++;
	adj.resize(rCnt);
	col.resize(cCnt);
	row.resize(rCnt);
	check.resize(rCnt, vector<bool> (cCnt, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (table[i][j] == 0 && !check[rTable[i][j]][cTable[i][j]]) {
				adj[rTable[i][j]].push_back(cTable[i][j]);
				check[rTable[i][j]][cTable[i][j]] = true;
			}
		}
	}
	int maxMatch = 0;
	for (int i = 1; i < rCnt; i++) {
		if (row[i] == 0) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) maxMatch++;
		}
	}
	printf("%d\n", maxMatch);
	return 0;
}