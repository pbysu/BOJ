#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int n, m, k;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
vector<vector<char>> arr;
vector<pair<int, int>> pos;

bool visited[1001][1001];

int bfs(int k) {
	queue< pair<int, int>> q;
	q.push({ pos[k].first, pos[k].second });
	int x = k+1;
	bool jd = true;
	int cnt = 0;
	while (!q.empty()) {

		cnt++;
		int siz = q.size();
		jd = false;
		for (int i = 0; i < siz; i++) {
			pair<int, int> tmp = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int tc = tmp.second + dc[i];
				int tr = tmp.first + dr[i];
				if (tr >= 0 && tr < n && tc >= 0 && tc < m && !visited[tr][tc] && (arr[tr][tc]=='S'||arr[tr][tc] == '.' || (arr[tr][tc] - '0' > 0 && arr[tr][tc] - '0' < 10))) {
					q.push({ tr,tc });
					visited[tr][tc] = true;
					if (arr[tr][tc] - '0' == x) {
						return cnt;
					}
				}
			}
		}
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	arr.resize(n, vector<char>(m));
	pos.resize(k + 1);

	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			scanf("%1c", &arr[i][j]);
			if (arr[i][j] == 'S') pos[0] = { i,j };
			else if (arr[i][j] - '0' > 0 && arr[i][j] - '0' < 10) pos[arr[i][j] - '0'] = { i,j };
		}
	}
	
	int ans = 0;
	for (int i = 0; i < k; i++) {
		ans += bfs(i);
		memset(visited, false, sizeof(visited));
	}
	printf("%d\n", ans);
	return 0;
}