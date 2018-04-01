#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAX 500
using namespace std;
int N, M, rc[MAX], stone[MAX];
vector<int>adj[MAX];
bool visited[MAX];

bool dfs(int pos) {
	visited[pos] = true;
	for (int next : adj[pos]) {
		if (stone[next]== 0|| !visited[stone[next]] && dfs(stone[next])) {
			rc[pos] = next;
			stone[next] = pos;
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d %d", &N, &M);
	for (int u, v, i = 1; i <= M; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
	}
	int match = 0;
	for (int i = 1; i <= N; i++) {
		if (rc[i] == 0) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) match++;
		}
	}

	printf("%d", match);
	return 0;
}