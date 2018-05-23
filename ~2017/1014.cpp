#include<cstdio>
#include<algorithm>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int dr[6] = { -1,-1,0,0 ,1,1};
int dc[6] = { -1,1,-1,1, 1,-1};
int evenTable[53], oddTable[53], T, N, M, even, odd;
bool visited[102];
int table[12][12];
int nTable[12][12];
vector<vector<int>> adj;

bool dfs(int here) {
	visited[here] = true;
	
	for (int there : adj[here]) {
		if (!evenTable[there] || !visited[evenTable[there]] && dfs(evenTable[there])) {
			oddTable[here] = there;
			evenTable[there] = here;
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		even = 0;
		odd = 0;
		int noCnt = 0;
		scanf("%d %d", &N, &M);
		memset(table, 0, sizeof(table));
		memset(evenTable, 0, sizeof(evenTable));
		memset(oddTable, 0, sizeof(oddTable));
		char tmp;
		for (int i = 1; i <= N; i++) {
			getchar();
			for (int j = 1; j <= M; j++) {
				scanf("%c", &tmp);
				if (tmp == '.') {
					if (j % 2 == 0)
						table[i][j] = ++even;
					else
						table[i][j] = ++odd;
				}
				else {
					noCnt++;
				}
			}
		}
		adj.clear();
		adj.resize(odd + 1);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j+=2) {
				if (table[i][j] != 0) {
					for (int k = 0; k < 6; k++) {
						if (table[i + dr[k]][j + dc[k]] != 0) {
							adj[table[i][j]].push_back(table[i + dr[k]][j + dc[k]]);
						}
					}
				}
			}
		}

		int match = 0;
		for (int i = 1; i <= odd; i++) {
			if (!oddTable[i]) {
				memset(visited, false, sizeof(visited));
				if (dfs(i)){match++;}
			}
		}


		printf("%d\n", even + odd - match);
	}

	return 0;
}