#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int t, n, k, w, buildTime[1001], inde[1001];
int total[1001];
void func(vector<vector<int>> &adj) {

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inde[i] == 0)
			q.push(i);
	}

	while (inde[w] > 0) {
		int cur = q.front();
		q.pop();
		for (int next : adj[cur]) {
			total[next] = max(total[next], total[cur] + buildTime[cur]);
			inde[next]--;
			if (inde[next] == 0)
				q.push(next);
		}
	}
	return ;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		vector<vector<int>> adj;
		memset(inde, 0, sizeof(inde));
		memset(total, 0, sizeof(total));
		for (int i = 1; i <= n; i++)scanf("%d", &buildTime[i]);
		adj.resize(n + 1);
		for (int u,v,i = 0; i < k; i++) {
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			inde[v]++;
		}
		scanf("%d", &w);
		func(adj);
		printf("%d\n", total[w]+buildTime[w]);
	}
	return 0;
}