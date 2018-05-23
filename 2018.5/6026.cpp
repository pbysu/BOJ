#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n, u, v, m, s[100001], e[100001], val, lazy[400001];
vector<vector<int>> adj;
void makeTree(int cur, int ex) {
	s[cur]= val++;
	for (auto next : adj[cur]) {
		if (next == ex)continue;
		makeTree(next, cur);
	}
	e[cur] = val-1;
}
int query(int pos, int node, int x, int y) {
	if (pos<x || y<pos)return 0;
	if (x==y) 
		return lazy[node];
	int mid = (x + y) / 2;
	lazy[node * 2] += lazy[node];
	lazy[node * 2 + 1] += lazy[node];
	lazy[node] = 0;
	return query(pos, node * 2, x, mid) + query(pos, node * 2 + 1, mid + 1, y);
}
void update(int lo, int hi, int val, int node, int x, int y) {
	if (hi< x || y < lo)return;
	if (lo<=x && y<=hi) {
		lazy[node] += val; return;
	}
	int mid = (x + y) >> 1;
	lazy[node * 2 + 1] += lazy[node];
	lazy[node * 2] += lazy[node];
	lazy[node] = 0;
	update(lo, hi, val, node * 2, x, mid);
	update(lo,hi, val, node * 2 + 1, mid + 1, y);
}
int main() {
	scanf("%d", &n); adj.resize(n + 1);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		u--, v--;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	makeTree(0, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &u);u--;
		printf("%d\n", query( s[u],1, 0, n-1));
		update(s[u], e[u], 1, 1, 0, n - 1);
	}
	return 0;
}