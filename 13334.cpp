#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii> table;
vector<int> seg;
vector<pii*> maxSort;
int n, d;
int update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y)return seg[node];
	else if (x == y) return seg[node]= val;
	int mid = (x + y) >> 1;
	int left = update(pos, val, node * 2, x, mid);
	int right = update(pos, val, node * 2 + 1, mid + 1, y);
	return seg[node] = left + right;
}
int query(int lo, int hi, int node, int x, int y) {
	if (y < lo || hi < x) return 0;
	else if (lo <= x && y <= hi) return seg[node];
	int mid = (x + y) >> 1;
	int left = query(lo, hi, node * 2, x, mid);
	int right = query(lo, hi, node * 2 + 1, mid + 1, y);
	return left + right;
}
int main() {
	scanf("%d", &n);
	seg.resize(n * 4);
	table.resize(n);
	maxSort.resize(n);
	for (int u, v, i = 0; i < n; i++) {
		scanf("%d %d", &u, &v);
		if (u < v) table[i] = { u,v };
		else table[i] = { v,u };
	}
	scanf("%d", &d);

	sort(table.begin(), table.end(), [](pii p, pii q) {
		if (p.first != q.first) {
			return p.first < q.first;
		}
		else
			return q.second < q.second;
	});
	for (int i = 0; i < n; i++) {
		maxSort[i] = &table[i];
	}
	sort(maxSort.begin(), maxSort.end(), [](pii* p, pii* q) {
		if (p->second != q->second)
			return p->second < q->second;
		else
			return p->first < q->first;
	});
	int idx;
	int ans = 0;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		int left = 0;
		int right = n;
		idx = maxSort[i] - &table[0];
		update(idx, 1, 1, 0, n - 1);
		int mid;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (table[mid].first < table[idx].second - d) {
				left = mid + 1;
			}
			else
				right = mid - 1;
		}

		ans = max(ans, query(left, n - 1, 1, 0, n - 1));
	}
	printf("%d\n", ans);
	return 0;
}