#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;
vector<int> h;
vector<vector<pair<int, int>>> adj;
int n, m, jh, k, tmp, u, v, c;
typedef pair<int, int> pii;
vector<int> di;

void dij(int s) {
	priority_queue<pii> pq;
	di[s] = 0;
	pq.push({ 0,s });
	while (pq.size()) {
		int size = pq.size();
		for (int i = 0; i < size; i++) {
			pii cur = pq.top();
			pq.pop();
			for (pii next : adj[cur.second]) {
				int there = next.first;
				int cost = -cur.first + next.second;
				if (di[there] > cost) {
					di[there] = cost;
					pq.push({ -cost, there });
				}
			}
		}
	}
}
int main() {
	scanf("%d %d \n%d \n %d", &n, &m,&jh, &k);
	h.resize(n + 1);
	adj.resize(n + 1);
	di.resize(n + 1, INF);
	for (int i = 0; i < k; i++) { scanf("%d", &tmp), h[tmp] = 1; }//a
	for (int i = 0; i < k; i++) { scanf("%d", &tmp), h[tmp] = 2; }//b
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back({ v,c });
		adj[v].push_back({ u,c });
	}

	dij(jh);
	pii one, two;
	one.first = one.second = two.first = two.second = INF;

	for (int i = 1; i <= n; i++) {
		if (h[i] == 1) {
			if (one.second > di[i])one.second = di[i];
			if (one.first > one.second)swap(one.first, one.second);
		}
		else if (h[i] == 2) {
			if (two.second > di[i])two.second = di[i];
			if (two.first > two.second)swap(two.first, two.second);
		}
	}
	if (one.first < two.first) printf("A\n%d", one.first);
	else if (two.first < one.first) printf("B\n%d", two.first);
	else if (one.first != INF) printf("A\n%d", one.first);
	else printf("-1\n");
	return 0;
}