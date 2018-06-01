#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1e9 * 90002;
ll arr[310][310];
int visited[310][310];
int n, m;
int dr[] = { 0,0,1, -1 ,  1,1, -1, -1 };
int dc[] = { 1, -1, 0 , 0,1,-1, 1, -1  };
ll dijkstra() {
	vector<vector<ll>> dij;
	dij.resize(n, (vector<ll>(m, INF)));
	priority_queue < pair<ll, pair<int, int>>> pq;
	for (int i = 0; i < m; i++) {
		if (arr[0][i] == -1)continue;
		pq.push({ -arr[0][i],{ 0,i } });
		dij[0][i] = arr[0][i];
	}
	while (!pq.empty()) {
		int r = pq.top().second.first;
		int c = pq.top().second.second;
		ll cost = -pq.top().first;
		pq.pop();
		for (int i = 0; i < 8; i++) {
			int tr = r + dr[i];
			int tc = c + dc[i];
			ll tcost = cost;
			if (tr >= 0 && tr < n && tc >= 0 && tc < m && arr[tr][tc]!=-1) {
				tcost += arr[tr][tc];
			}
			else continue;
			if (tcost < dij[tr][tc]) {
				pq.push({ -tcost, {tr,tc} });
				dij[tr][tc] = tcost;
			}
		}
	}
	ll ret = INF;
	for (int i = 1; i < n; i++) {
		ret = min(dij[i][0], ret);
	}
	for (int i = 0; i < m ; i++) {
		ret = min(dij[n - 1][i], ret);
	}
	return ret;
}


ll bdijkstra() {
	vector<vector<ll>> dij;
	dij.resize(n, (vector<ll>(m, INF)));
	priority_queue < pair<ll, pair<int, int>>> pq;
	for (int i = 0; i < n; i++) {
		if (arr[i][m-1] == -1)continue;
		pq.push({ -arr[i][m - 1],{ i,m-1 } });
		dij[i][m-1] = arr[i][m - 1];
	}
	while (!pq.empty()) {
		int r = pq.top().second.first;
		int c = pq.top().second.second;
		ll cost = -pq.top().first;
		pq.pop();
		for (int i = 0; i < 8; i++) {
			int tr = r + dr[i];
			int tc = c + dc[i];
			ll tcost = cost;
			if (tr >= 0 && tr < n && tc >= 0 && tc < m && arr[tr][tc] != -1) {
				tcost += arr[tr][tc];
			}
			else continue;
			if (tcost < dij[tr][tc]) {
				pq.push({ -tcost,{ tr,tc } });
				dij[tr][tc] = tcost;
			}
		}
	}
	ll ret = INF;
	for (int i = 0; i < m; i++) {
		ret = min(dij[n-1][i], ret);
	}
	for (int i = 0; i < n; i++) {
		ret = min(dij[i][0], ret);
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%lld", &arr[i][j]);
			if (arr[i][j] == -2) arr[i][j] = 0;
		}
	}
	ll ans = INF;

	ans = min(ans, dijkstra());
	ans = min(ans, bdijkstra());
	if (ans >= INF)
		ans = -1;
	printf("%lld", ans);

	return 0;
}
