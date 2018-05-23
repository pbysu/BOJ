#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#define De 18
using namespace std;
typedef long long ll;
int n, m, u, v, par[200001], save[200001][3], cnt, tcnt, w, maxw;
int p[200001][De+1];
int pc[200001];
int dep[200001];
ll cost, tcost;
priority_queue<pair<int, pair<int, int>>> pq;
vector<pair<int, int>> adj[200001];
set<pair<int,pair<int, int>>> used;
int find(int v) {
	if (par[v] == 0) return v;
	return par[v] = find(par[v]);
}
bool merge(int u, int v) {
	v = find(v);
	u = find(u);
	if (u == v) return false;
	par[u] = v;
	return true;
}

void dfs(int cur) {
	for (auto next : adj[cur]) {
		if (!dep[next.first]) {
			dep[next.first] = dep[cur] + 1;
			p[next.first][0] = cur;
			pc[next.first] = next.second;
			dfs(next.first);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		if (u > v)swap(u, v);
		save[i][0] = u;
		save[i][1] = v;
		save[i][2] = w;
		pq.push({ -w,{u,v} });
	}

	for (int i = 0; i < m; i++) {
		u = pq.top().second.first;
		v = pq.top().second.second;
		w = -pq.top().first;
		pq.pop();
		if (merge(u, v)) {
			used.insert({ w,{ u,v } });
			cnt++;
			cost += (ll)w;
			if (cnt == n - 1) break;
		}
	}
	auto it = used.begin();
	for (int i = 0; i < n - 1; i++) {
		w = it->first;
		u = it->second.first;
		v = it->second.second;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
		it++;
	}

	dep[1] = 1;
	memset(p, -1, sizeof(p));
	dfs(1);
	for (int j = 0; j <= De; j++) {
		for (int i = 1; i <= n; i++) {
			if (p[i][j] != -1) {
				p[i][j + 1] = p[p[i][j]][j];
			}
		}
	}
	for (int i = 0; i < m; i++) {
		u = save[i][0];
		v = save[i][1];
		w = save[i][2];
		if (used.find({ w,{ u,v } }) != used.end()) {
			printf("%lld\n", cost);
		}
		else {
			if (dep[u] > dep[v]) swap(u, v);
			int diff = dep[v] - dep[u];
			int st = v;
			int stu = u;
			maxw = 0;
			for (int k = 0; diff; k++) {
				if (diff % 2 == 1) { v = p[v][k]; }
				diff /= 2;
			}
			if (u != v) {
				for (int j = De; j >= 0; j--) {
					if (p[v][j] != -1 && p[u][j] != p[v][j]) {
						u = p[u][j];
						v = p[v][j];
					}
				}
				u = p[u][0];
			}
			while (st != u) {
				maxw = max(pc[st], maxw);
				st = p[st][0];
			}
			while (stu != u) {
				maxw = max(pc[stu], maxw);
				stu = p[stu][0];
			}
			printf("%lld\n", cost-maxw+save[i][2]);
		}
	}
	return 0;
}