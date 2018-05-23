#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, o, s, e;
vector<int> seg;
vector<int> lazy;

void propagation(int node, int x, int y) {
	if (!lazy[node])return;
	seg[node] = (y - x + 1) - seg[node];
	if (x != y) {
		lazy[node * 2] ^= 1;
		lazy[node * 2 + 1] ^= 1;
	}
	lazy[node] = 0;
}

int update(int lo, int hi, int val, int node, int x, int y) {
	propagation(node, x, y);
	if (y < lo || hi < x) return seg[node];
	if (lo <= x && y <= hi) {
		lazy[node] ^= 1;
		propagation(node, x, y);
		return seg[node];
	}
	int mid = (x + y) >> 1;
	int left = update(lo, hi, val, node * 2, x, mid);
	int right = update(lo, hi, val, node * 2 + 1, mid + 1, y);
	return seg[node] = left + right;
}

int query(int lo, int hi, int node, int x, int y) {
	propagation(node, x, y);
	if (y < lo || hi < x)
		return 0;
	if (lo <= x && y <= hi)
		return seg[node];

	int mid = (x + y) >> 1;
	int left = query(lo, hi, node * 2, x, mid);
	int right = query(lo, hi, node * 2 + 1, mid + 1, y);
	return left + right;
}
int main() {
	scanf("%d %d", &n, &m);
	seg.resize(n * 4);
	lazy.resize(n * 4); 

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &o, &s, &e);

		if (o) {
			printf("%d\n", query(s - 1, e - 1, 1, 0, n - 1));
		}
		else {
			update(s - 1, e - 1, 1, 1, 0, n - 1);
		}
	}

	return 0;
}