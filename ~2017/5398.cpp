#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
int T, N= 2002, M= 2002, H, V, cnt;
int rTable[2002][2002];
int cTable[2002][2002];
char table[2002][2002];
vector<vector<int>> adj;
char tmp[1001];
bool visited[2002];
int r[2002];
int c[2002];
bool dfs(int here) {
	visited[here] = true;

	for (int next : adj[here]) {
		if (!c[next] || !visited[c[next]] && dfs(c[next])) {
			c[next] = here;
			r[here] = next;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &H, &V);
		adj.clear();
		adj.resize(1001);
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
		memset(table, NULL, sizeof(table));
		cnt = 0;
		for (int r, c, i = 0; i < H; i++) {
			scanf("%d %d %s", &c, &r, &tmp);
			cnt++;
			for(int j = 0; j<strlen(tmp); j++){
				table[r][c + j] = tmp[j];
				rTable[r][c + j] = cnt;
			}
		}
		int rowSize = cnt;
		cnt = 0;
		for (int r, c, i = 0; i < V; i++) {
			scanf("%d %d %s", &c, &r, &tmp);
			cnt++;
			for (int j = 0; j<strlen(tmp); j++) {
				if (table[r+j][c]!='\0' && table[r + j][c] != tmp[j]) {
					adj[rTable[r + j][c]].push_back(cnt);
				}
				table[r + j][c] = tmp[j];
				cTable[r+j][c] = cnt;
			}
		}
		int colSize = cnt;
		int ans = 0;
		for (int i = 1; i <= rowSize; i++) {
			if (!r[i]) {
				memset(visited, false, sizeof(visited));
				if (dfs(i)) ans++;
			}
		}

		printf("%d\n", colSize + rowSize - ans);
	}

	return 0;
}