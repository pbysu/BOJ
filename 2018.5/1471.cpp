#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
int n, val;
int de[200001], adj[200001], cost[200001];
queue<int> q;
map<int, bool> ma;

inline int getNext(int cur) {
	int tmp = cur;
	int a = 0;
	while (tmp) {
		a += tmp % 10;
		tmp /= 10;
	}
	tmp = (a + cur) % n;
	if (!tmp) tmp = n;
	return tmp;
}

void bfs() {
	while (q.size()) {
		int cur = q.front(); q.pop();
		int next = adj[cur];
		cost[next] = max(cost[next], cost[cur] + 1);
		if (--de[next] == 0)
			q.push(next);

	}
}


int dfs(int cur, int s) {
	val = max(val, cost[cur]);
	de[cur]--;
	if (adj[cur] != s) return 1 + dfs(adj[cur], s);
	else
		return 1;
}

int main() {
	scanf("%d", &n);
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		adj[i] = getNext(i);
		de[adj[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (de[i] == 0) {
			q.push(i);
		}
	}
	bfs();
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (de[i]>0) {
			val = 0;
			ret = max(dfs(i, i) + val, ret);
		}
	}
	printf("%d", ret);
	return 0;
}