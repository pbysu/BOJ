#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>;
using namespace std;
int n, k;
vector<int> seg;
queue<int>idx;
int update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y) return seg[node];
	if (x == y)
		return seg[node] = val;

	int mid = (x + y) >> 1;

	int left = update(pos, val, node * 2, x, mid);
	int right = update(pos, val, node * 2 + 1, mid + 1, y);

	return seg[node] = left + right;
}

int query(int lo, int hi, int node, int x, int y) {
	if (hi > n - 1) {
		return query(lo, n - 1, node, x, y) + query(0, hi - n + 1, node, x, y);
	}
	if (hi<x || lo>y) return 0;
	if (lo <= x&&y <= hi) return seg[node];

	int mid = (x + y) >> 1;

	int left = query(lo, hi, node * 2, x, mid);
	int right = query(lo, hi, node * 2 + 1, mid + 1, y);

	return left + right;
}

int find(int val, int node, int x, int y) {

	if (x == y) return x;
	int mid = (x + y) >> 1;

	if (seg[node * 2] < val) {
		return find(val - seg[node * 2], node * 2 + 1, mid + 1, y);
	}

	else {
		return find(val, node * 2, x, mid);
	}
}

int main() {
	scanf("%d %d", &n, &k);
	seg.resize(n * 4);

	for (int i = 0; i < n; i++) {
		update(i, 1, 1, 0, n - 1);
	}
	int pos = 0, ex = 0, val = 0;
	int sum;
	int total = seg[1];
	int siz;

	for (int i = 0; i < n; i++) {
		sum = query(ex, n - 1, 1, 0, n - 1);

		if ( sum>= k) {
			pos = find(query(0, ex - 1, 1, 0, n - 1) + k, 1, 0, n - 1);
		}
		else {
			siz = (k - sum) % total;
			if (siz == 0) siz = total;
			pos = find(siz, 1, 0, n - 1);
		}
		update(pos, 0, 1, 0, n - 1);
		idx.push(pos);
		ex = pos;
		total--;
	}

	printf("<");
	total = idx.size();
	for (int i = 1; i < total; i++) {
		printf("%d, ", idx.front() + 1);
		idx.pop();
	}
	printf("%d>", idx.front() + 1);

	return 0;
}