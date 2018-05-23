#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n, m, k;
vector<pair<int, int>>node;
vector<int> cur;
vector<int> seg;
vector<pair<int, int>*> ptr;
int update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y)return seg[node];
	if (x == y) return seg[node] = val;
	int mid = (x + y) >> 1;

	int left = update(pos, val, node * 2, x, mid);
	int right = update(pos, val, node * 2 + 1, mid + 1, y);
	return seg[node] = min(left, right);
}
int query(int lo, int hi, int node, int x, int y) {
	if (x > hi || lo > y) return 987654321;
	if (lo <= x && y <= hi)return seg[node];

	int mid = (x + y) >> 1;
	int left = query(lo, hi, node * 2, x, mid);
	int right = query(lo, hi, node * 2 + 1, mid + 1, y);

	return min(left, right);
}
int tmp;
int main() {
	scanf("%d", &n);
	node.resize(n);
	cur.resize(n);
	seg.resize(n * 4, 987654321);
	ptr.resize(n);
	for (int i = 0; i < n; i++)scanf("%d", &tmp), node[tmp-1].first = i;
	for (int i = 0; i < n; i++)scanf("%d", &tmp), node[tmp-1].second =i;
	for (int i = 0; i < n; i++)scanf("%d", &tmp), cur[tmp-1] = i;
	for (int i = 0; i < n; i++) ptr[i] = &node[i];

	sort(ptr.begin(), ptr.end(),
		[](pair<int, int>* p, pair<int, int>*q) {
		return p->first < q->first;
	});
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int pos = ptr[i] - &node[0];
		tmp = query(0, node[pos].second, 1, 0, n - 1);
		if ( tmp>  cur[pos])
			ans++;
		update(node[pos].second, cur[pos], 1, 0, n - 1);
	}
	printf("%d", ans);
	return 0;
}