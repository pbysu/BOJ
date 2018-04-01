#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int n, m;
int arr[10][10];
bool visited[10][10];
vector<pair<int, int>> s;
int total = 0;
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1,-1, 0, 0 };

int dfs(int r, int c) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int tr = r + dr[i];
		int tc = c + dc[i];
		if (tr >= 0 && tr < n && tc >= 0 && tc < m && !visited[tr][tc] && arr[tr][tc] == 0) {
			visited[tr][tc] = true;
			ret += dfs(tr, tc) + 1;
		}
	}
	return ret;
}
int func(int r, int c, int cnt) {
	if (cnt == 3) {
		int x = 0;
		for (int i = 0; i < s.size(); i++) {
			x += dfs(s[i].first, s[i].second);
		}
		memset(visited, false, sizeof(visited));
		return total - cnt - x;
	}
	if (c == m) return func(r + 1, 0, cnt);
	if (r == n) return 0;

	int ret = 0;
	if (arr[r][c] == 0) {
		arr[r][c] = 1;
		ret = func(r, c + 1, cnt + 1);
		arr[r][c] = 0;
	}
	return ret = max(func(r, c + 1, cnt), ret);
}
int main() {
	scanf("%d %d", &n, &m);
	int sibal = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) s.push_back({ i,j });
			else if (arr[i][j] == 0) total++;
		}
	}
	int ans = func(0, 0, 0);
	printf("%d\n", ans);
	return 0;
}