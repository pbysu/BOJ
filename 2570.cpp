#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int N, M, cnt;
bool check[101][101][2];
int rlTable[101][101];
int rhTable[101][101];
int dr[] = { 1,-1,    1,-1 };
int dc[] = { 1, -1,  -1, 1 };
typedef pair<int, int> pii;
vector<vector<int>> adj;
vector<vector<bool>> match;
vector<int> rh;
vector<int> rl;
vector<bool> visited;

bool dfs(int pos) {
	visited[pos] = true;
	for (int next : adj[pos]) {
		if (!rl[next] || !visited[rl[next]] && dfs(rl[next])) {
			rh[pos] = next;
			rl[next] = pos;
			return true;
		}
	}
	return false;
}

void rhFunc(int r, int c, int cnt) {
	check[r][c][0] = true;
	rhTable[r][c] = cnt;
	for (int i = 0; i < 2; i++) {
		int tr = r + dr[i];
		int tc = c + dc[i];
		if (tr > 0 && tr <= N && tc > 0 && tc <= N && !check[tr][tc][0]) {
			rhFunc(tr, tc, cnt);
		}
	}
}
void rlFunc(int r, int c, int cnt) {
	check[r][c][1] = true;
	rlTable[r][c] = cnt;
	for (int i = 2; i < 4; i++) {
		int tr = r + dr[i];
		int tc = c + dc[i];
		if (tr > 0 && tr <= N && tc > 0 && tc <= N && !check[tr][tc][1]) {
			rlFunc(tr, tc, cnt);
		}
	}
}
int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	for (int y,x, i = 0; i < M; i++) {
		scanf("%d %d", &y, &x);
		check[y][x][0] = true;
		check[y][x][1] = true;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (check[i][j][0] == false) {
				rhFunc(i, j,++cnt);
			}
		}
	}
	adj.resize(cnt + 1);
	int tmp = cnt;
	cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (check[i][j][1] == false) {
				rlFunc(i, j,++cnt);
			}
		}
	}
	match.resize(tmp + 1, vector<bool>(cnt + 1, false));
	rh.resize(tmp + 1);
	rl.resize(cnt + 1);
	visited.resize(tmp + 1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!match[rhTable[i][j]][rlTable[i][j]]) {
				match[rhTable[i][j]][rlTable[i][j]] = true;
				adj[rhTable[i][j]].push_back(rlTable[i][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= tmp; i++) {
		if (!rh[i]) {
			fill(visited.begin(), visited.end(), false);
			if (dfs(i)) ans++;
		}
	}
	printf("%d", ans);
	return 0;
}