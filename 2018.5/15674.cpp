#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<pair<int, int>> v;
vector<int> p;
vector<pair<int, int>> save;
int n, d, a, b, c;
int find(int u) {
	if (p[u] == -1)return u;
	
}
bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)return false;
	p[v] = u;
	save[u].first += save[v].first;
	save[u].second += save[u].second;
	return true;
}
int main() {
	scanf("%d %d", &n, &d);
	v.resize(n+1); p.resize(n + 1, -1); save.resize(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &v[i].first, &v[i].second), save[i] = v[i];
	for (int i = 0; i < d; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) {
			merge(b, c);
		}
		else if (a == 1) {

		}
	}

	return 0;
}