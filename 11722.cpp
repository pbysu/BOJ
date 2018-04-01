#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v;
vector<pair<int,int>> vr;
int seg[4001];

int update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y) return seg[node];
	if (x == y) return seg[node] = val;

	int mid = (x + y) >> 1;

	int left = update(pos, val, node * 2, x, mid);
	int right = update(pos, val, node * 2 + 1, mid+1, y);

	return seg[node] = max(left ,right);
}

int query(int lo, int hi, int node, int x, int y) {
	if (lo > y || hi < x) return 0;
	if (lo <= x&&y <= hi) return seg[node];

	int mid = (x + y) >> 1;

	int left = query(lo, hi, node * 2, x, mid);
	int right = query(lo, hi, node * 2 + 1, mid + 1, y);

	return max(left ,right);
}

int main() {
	int n;
	scanf("%d", &n);
	v.resize(n);
	vr.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		vr[i].first = v[i];
		vr[i].second = i;
	}

	sort(vr.begin(), vr.end(), [](pair<int, int>p, pair<int, int> q) {
		if (p.first != q.first)
			return p.first >q.first;
		else
			return p.second > q.second;
	});


	int idx = 0;
	int siz = 0;
	for (int i = 0; i < n; i++) {
		idx = vr[i].second;
		siz = query(0, idx, 1, 0, n - 1) + 1;
		update(idx, siz, 1, 0, n - 1);
	}
	printf("%d", seg[1]);

	return 0;
}