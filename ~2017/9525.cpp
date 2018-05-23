#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int rCnt, cCnt, N, M, rTable[101][101], cTable[101][101];
char table[101][101];
bool visited[10000];
vector<vector<int>> adj;
vector<int> row, col;

bool dfs(int pos) {
	visited[pos] = true;
	for (int next : adj[pos]) {
		if (!col[next] || !visited[col[next]] && dfs(col[next])) {
			row[pos] = next;
			col[next] = pos;
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) scanf("%s", &table[i]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (table[i][j] == '.') {
				if (j == 0) rTable[i][j] = ++rCnt;
				else {
					if (table[i][j - 1] == '.') rTable[i][j] = rTable[i][j - 1];
					else rTable[i][j] = ++rCnt;
				}
			}
		}
	}

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (table[i][j] == '.') {
				if (i == 0) cTable[i][j] = ++cCnt;
				else {
					if (table[i-1][j] == '.') cTable[i][j] = cTable[i-1][j];
					else cTable[i][j] = ++cCnt;
				}
			}
		}
	}
	++rCnt, ++cCnt;
	adj.resize(rCnt);
	col.resize(cCnt);
	row.resize(rCnt);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (table[i][j] == '.') {
				adj[rTable[i][j]].push_back(cTable[i][j]);
			}
		}
	}

	int maxMatch = 0;
	for (int i = 1; i < rCnt; i++) {
		if (!row[i]) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) maxMatch++;
		}
	}

	printf("%d", maxMatch);
	return 0;
}