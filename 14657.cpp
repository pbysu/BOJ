#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAX_IN 50001
using namespace std;
typedef pair<int, int> pii;
bool visited[MAX_IN];
vector < vector<pair<int, int>>> adj;
int n, t, u, v, c, root;
pii rootCntCost = { -1,-1 };
void func(int pos, int cnt, int cost) {
	visited[pos] = true;
	if (cnt >= rootCntCost.first) {
		if (cnt > rootCntCost.first || (cnt == rootCntCost.first && cost < rootCntCost.second)) {
			rootCntCost = { cnt,cost };
			root = pos;
		}
	}
	for (pii next : adj[pos]) {
		if (visited[next.first])continue;
		func(next.first, cnt + 1, cost + next.second);
	}
}
int main() {
	scanf("%d %d", &n, &t);
	adj.resize(n + 1);
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back({ v,c });
		adj[v].push_back({ u,c });
	}
	func(1, 1, 0);
	memset(visited, false, sizeof(visited));
	rootCntCost = { 0,0 };
	func(root, 1, 0);
	int ans = rootCntCost.second;
	ans = ans / t + (ans%t == 0 ? 0 : 1);
	printf("%d\n", ans);
	return 0;
}