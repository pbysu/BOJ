#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define MaxNote 5001
#define MaxHum 101

using namespace std;
int N, M, note[MaxNote], human[MaxHum];
bool visited[MaxHum];
vector<int> adj[MaxHum];

bool dfs(int hum) {
	visited[hum] = true;
	for (int next : adj[hum]) {
		if (note[next] == 0 || !visited[note[next]] && dfs(note[next])) {
			human[hum] = next;
			note[next] = hum;
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d %d", &N, &M);
	for (int u, v, i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
	}
	int match = 0;

	for (int i = 1; i <= N; i++) {
		if (human[i] == 0) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) match++;
		}
	}
	printf("%d\n", match);
	return 0;
}