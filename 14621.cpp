#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
char tmp;
bool sex[1001];
int n, m, u, v, c, p[1001];
priority_queue<pair<int, pair<int, int>> >pq;

int find(int u) {
	if (p[u] == 0) return u;
	else {
		return p[u] = find(p[u]);
	}
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v) {
		p[u] = v;
		return true;
	}
	else {
		return false;
	}
}
int main() {
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 1; i <= n; i++) {
		scanf("%c ", &tmp); if (tmp == 'M') sex[i] = true;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &c);
		if (!(sex[u] && sex[v]) && (sex[u] || sex[v])) {
			pq.push({ -c,{u,v} });
		}
	}
	int ret = 0;
	int cnt = 0;
	while (pq.size()) {
		u = pq.top().second.first, v = pq.top().second.second, c = -pq.top().first;
		pq.pop();
		if (merge(u, v)) {
			cnt++;
			ret += c;
			if (cnt == n - 1)
				break;
		}
	}

	if (cnt != n - 1) printf("-1\n");
	else printf("%d\n", ret);
	return 0;
}