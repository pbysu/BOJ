#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAX 1002
using namespace std;
int N, M, rc[MAX], stone[MAX];
vector<int>adj[MAX];
bool visited[MAX];

bool dfs(int pos) {
	visited[pos] = true;
	for (int next : adj[pos]) {
		if (stone[next] == 0 || !visited[stone[next]] && dfs(stone[next])) {
			rc[pos] = next;
			stone[next] = pos;
			return true;
		}
	}
	return false;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < MAX; i++) {
			adj[i].clear();
		}
		memset(rc, 0, sizeof(rc));
		memset(stone, 0, sizeof(stone));
		scanf("%d %d", &N, &M);
		for (int u, v, i = 1; i <= M; i++) {
			scanf("%d %d", &u, &v);
			for (int j = u; j <= v; j++) {
				adj[i].push_back(j);
			}
		}
		int match = 0;
		for (int i = 1; i <= M; i++) {
			if (rc[i] == 0) {
				memset(visited, false, sizeof(visited));
				if (dfs(i)) match++;
			}
		}
		printf("%d\n", match);
	}
	return 0;
}