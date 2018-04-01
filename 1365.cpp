#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int> seg;
vector<pair<int, int>> in;
int update(int pos, int node, int val, int x, int y) {
	if (pos<x || pos>y)return seg[node];
	if (x == y) return seg[node] = val;
	int mid = (x + y) >> 1;
	int left = update(pos, node * 2, val, x, mid);
	int right = update(pos, node * 2 + 1, val, mid + 1, y);
	return seg[node] = max(left, right);
}
int query(int lo, int hi, int node, int x, int y) {
	if (x > hi || lo > y) return 0;
	if (lo <= x && y <= hi) return seg[node];
	int mid = (x + y) >> 1;
	int left = query(lo, hi, node * 2, x, mid);
	int right = query(lo, hi, node * 2 + 1, mid + 1, y);
	return max(left, right);
}
int main() {
	scanf("%d", &n);
	seg.resize(n * 4);
	in.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i].first);
		in[i].second = i;
	}

	sort(in.begin(), in.end(), [](pair<int, int> p, pair<int, int> q) {
		return p.first < q.first;
	});
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		tmp = query(0, in[i].second, 1, 0, n - 1)+1;
		update(in[i].second, 1,tmp, 0, n - 1);
	}

	printf("%d", n - seg[1]);
	return 0;
}