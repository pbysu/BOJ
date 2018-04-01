#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
int n, in[1000001], out[1000001];
int visited[1000001];
vector<int> adj[1000001];
bool dfs(int here,int k) {
	visited[here] = k;
	for (int next : adj[here]) {
		if (!out[next] || visited[out[next]]!=k && dfs(out[next], k)) {
			out[next] = here;
			in[here] = next;
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d", &n);
	for (int u, v, i = 1; i <= n; i++) {
		scanf("%d %d", &u, &v);
		adj[i].push_back(v);
		adj[i].push_back(u);
	}
	int miss = 0;
	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			if(dfs(i,i)) miss++;
		}
	}

	if (n != miss) {
		printf("-1\n");
	}
	else {
		for (int i = 1; i <= n; i++) {
			printf("%d\n", in[i]);
		}
	}
	return 0;
}