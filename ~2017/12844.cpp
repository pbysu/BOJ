#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> seg;
vector<int> lazy;
vector<int> input;

void init(int node, int x, int y) {
	if (x == y)
	{ seg[node] = input[x]; return; }
	int mid = (x + y) >> 1;
	init(node * 2, x, mid);
	init(node * 2 + 1, mid + 1, y);
	seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
}

int propagation(int node, int x, int y) {
	if (!lazy[node])return seg[node];
	if (x == y) seg[node] ^= lazy[node];
	else {
		lazy[node * 2] ^= lazy[node];
		lazy[node * 2 + 1] ^= lazy[node];
		if ((y - x + 1) % 2) seg[node] ^= lazy[node];
		else seg[node];
	}
	lazy[node] = 0;
	return seg[node];
}
int update(int lo, int hi,int val, int node, int x, int y) {
	propagation(node, x, y);
	if (lo > y || hi < x)return seg[node];
	if (lo <= x&&y <= hi) {
		lazy[node] = val;
		return propagation(node, x, y);
	}
	int mid = (x + y) >> 1;
	int left = update(lo, hi, val, node * 2, x, mid);
	int right = update(lo, hi, val, node * 2 + 1, mid + 1, y);
	return seg[node] = left^right;
}

int query(int lo, int hi, int node, int x, int y) {
	propagation(node, x, y);
	if (lo > y || hi < x)return 0;
	if (lo <= x && y <= hi) return seg[node];
	int mid = (x + y) >> 1;
	int left = query(lo, hi, node * 2, x, mid);
	int right = query(lo, hi, node * 2 + 1, mid + 1, y);
	return left^right;
}
int main() {
	int n;
	scanf("%d", &n);
	seg.resize(n * 4);
	lazy.resize(n * 4);
	input.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &input[i]);
	init(1, 0, n-1);
	int m;
	scanf("%d", &m);
	for (int t,a,b,c, i = 0; i < m; i++) {
		scanf("%d ", &t);
		if (t == 1) {
			scanf("%d %d %d", &a, &b, &c);
			if (a > b)swap(a, b);
			update(a, b, c,1,0,n-1);
		}
		else {
			scanf("%d %d", &a, &b);
			if (a > b)swap(a, b);
			printf("%d\n", query(a, b, 1, 0, n - 1));
		}
	}
	return 0;
}