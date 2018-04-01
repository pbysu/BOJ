#include<iostream>
#include<algorithm>
#include<vector>
#define mod 1000000007
using namespace std;

int n, m, k;
typedef long long ll;
vector<ll> seg;

ll update(int pos, int val, int node, int x, int y) {
	if(pos<x||pos>y) return seg[node];
	if (x == y) return seg[node] = val;
	
	int mid = (x + y) >> 1;

	ll left = update(pos, val, node * 2, x, mid);
	ll right = update(pos, val, node * 2 + 1, mid + 1, y);

	return seg[node] = (left*right) % mod;
}

ll query(int lo, int hi, int node, int x, int y) {
	if (hi<x || lo>y) return 1;
	if (lo <= x&&y <= hi) return seg[node];

	int mid = (x + y) >> 1;

	ll left = query(lo, hi, node * 2, x, mid);
	ll right = query(lo, hi, node * 2 + 1, mid + 1, y);

	return (left*right) % mod;
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	seg.resize(n * 4);
	int temp, a, b, c;

	for (int i = 0; i < n; i++) scanf("%d", &temp), update(i, temp, 1, 0, n - 1);

	for (int i = 0; i < m + k; i++) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == 1)
			update(b - 1, c, 1, 0, n - 1);
		else
			printf("%lld\n", query(b - 1, c - 1, 1, 0, n - 1));
	}
	return 0;
}