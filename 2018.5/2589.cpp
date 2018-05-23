#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
char arr[51][51];
bool visited[51][51];
int cost[51][51];
queue<pair<int,int>> q;
int n, m;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		getchar();
		for (int j = 0; j < m; j++) {
			scanf("%c", &arr[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L') {
				visited[i][j] = true;
				q.push({ i,j });
				int cnt = 0;
				memset(visited, false, sizeof(visited));
				while (q.size()) {
					cnt++;
					ans = max(ans, cnt);
					int siz = q.size();
					for (int i = 0; i < siz; i++) {
						int r = q.front().first;
						int c = q.front().second;
						q.pop();
						for (int i = 0; i < 4; i++) {
							int tr = r + dr[i];
							int tc = c + dc[i];
							if (tr >= 0 && tr < n && tc >= 0 && tc < m && !visited[tr][tc] && arr[tr][tc]=='L') {
								visited[tr][tc] = true;
								cost[tr][tc] = cnt;
								q.push({ tr,tc });
							}
						}
					}
				}
			}
		}
	}
	printf("%d", ans-1);
	return 0;
}