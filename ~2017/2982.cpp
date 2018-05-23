#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>	
#include<algorithm>
#define INF 1e9
using namespace std;
int a, b, k, g, u, v, c, n, m;
vector<vector<pair<int, int>>> adj;
vector<int> load;
vector<pair<int, pair<int, int>>> x;


int dij() {
	vector<int> di(n+1, INF);
	di[a] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ -k,a });

	while (!pq.empty()) {
		int siz = pq.size();
		for (int i = 0; i < siz; i++) {
			int cur = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();
			for (pair<int,int> temp : adj[cur]) {
				int next = temp.first;
				int pCost;
				if (x[cur].first == next
					&& x[cur].second.first <= cost
					&& x[cur].second.second >= cost
					)
					pCost = x[cur].second.second + temp.second;
				else if(
					 x[next].first == cur
					&& x[next].second.first <= cost
					&& x[next].second.second >= cost
				
					)
					pCost = x[next].second.second + temp.second;
				else
					pCost = cost + temp.second;
				if (di[next] > pCost) {
					di[next] = pCost;
					pq.push({ -pCost, next });
				}
			}
		}
	}

	return di[b];
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d %d %d", &a, &b, &k, &g);
	load.resize(g + 1, 0);
	adj.resize(n + 1);
	x.resize(n + 1);
	for (int i = 0; i < g; i++) {
		scanf("%d", &load[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back({ v,c });
		adj[v].push_back({ u, c });
	}
	int tim = 0;
	for (int i = 0; i < g - 1; i++) {
		x[load[i]].first = load[i + 1];
		x[load[i]].second.first = tim;
		for (auto next : adj[load[i]]) {
			if (next.first == load[i + 1]) {
				tim += next.second;
				break;
			}
		}
		x[load[i]].second.second = tim;
	}
	printf("%d", dij()-k);


	return 0;
}