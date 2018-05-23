#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAX 2600
using namespace std;
int N, M, rCnt, cCnt, rTable[51][51], cTable[51][51];
char table[51][51];
vector<vector<int>> adj;
vector<int>row;
vector<int> col;
bool visited[MAX];

bool dfs(int pos) {
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
		scanf("%s", &table[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (table[i][j] == '*') {
				if (j == 0) {
					rTable[i][j] = ++rCnt;
				}
				else {
					if (table[i][j - 1] == '*') rTable[i][j] = rTable[i][j - 1];
					else rTable[i][j] = ++rCnt;
				}
			}
		}
	}

	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {
			if (table[i][j] == '*') {
				if (i == 0) cTable[i][j] = ++cCnt;
				else {
					if (table[i - 1][j] == '*') cTable[i][j] = cTable[i - 1][j];
					else cTable[i][j] = ++cCnt;
				}
			}
		}
	}
	rCnt++;
	cCnt++;
	adj.resize(rCnt);
	row.resize(rCnt,0);
	col.resize(cCnt,0);
	for(int i =0; i< N; i++){
		for (int j = 0; j < M; j++) {
			if (table[i][j] == '*') {
				adj[rTable[i][j]].push_back(cTable[i][j]);
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
	printf("%d", maxMatch);
	return 0;
}