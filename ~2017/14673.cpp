#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
int arr[5][10][10], n, m;
int visited[5][10][10];
int dr[] = { 0,0, 1, -1 };
int dc[] = { 1,-1, 0, 0 };

int dfs(int turn, int r, int c) {
	visited[turn-1][r][c] = true;
	int ret = 1;
	int tr, tc;
	for (int i = 0; i < 4; i++) {
		tr = r + dr[i];
		tc = c + dc[i];
		if (tr >= 0 && tr < n && tc >= 0 &&
			tc < m && arr[turn][tr][tc] == arr[turn][r][c] && !visited[turn-1][tr][tc]) {
			ret +=dfs(turn, tr, tc);
		}
	}
	arr[turn][r][c] = 0;
	return ret;
}

int func(int turn, int r, int c) {
	if (turn == 4)
		return 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[turn][i][j] = arr[turn - 1][i][j];
		}
	}
	int ret = dfs(turn, r, c);
	ret *= ret;
	for (int i = 0; i < m; i++) {
		int a = 0;
		int b = 1;
		while (true) {
			while (arr[turn][a][i] != 0&&a<=n)
				a++;
			b = a+1;
			while (arr[turn][b][i] == 0&&b<=n)
				b++;
			if (b >= n)break;
			swap(arr[turn][a][i], arr[turn][b][i]);
			a++;
		}
	}
	int tmp = 0;
	if (turn < 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[turn][i][j] != 0 && !visited[turn][i][j]) {
					tmp = max(tmp, func(turn + 1, i, j));
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			visited[turn][i][j] = false;
	}
	ret += tmp;
	return ret;
}
int main() {
	scanf("%d %d", &m, &n);
	int turn = 0;
	for (int i = n-1; i >=0;i--) {
		for (int j = m-1; j >=0 ; j--) {
			scanf("%d", &arr[0][i][j]);
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[turn][i][j]) {
				ret = max(ret, func(turn + 1, i, j));
			}
		}
	}
	printf("%d", ret);
	return 0;
}