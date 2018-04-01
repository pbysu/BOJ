#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> pos;
vector<int> seg;

int init(int node, int x, int y) {
	if (x == y)
		return seg[node] = 1;
	int mid = (x + y) >> 1;
	return seg[node] = init(node * 2, x, mid) + init(node * 2 + 1, mid + 1, y);
}
int query(int lo, int hi,int node, int x, int y) {
	if (lo > y || hi < x)return 0;
	if (lo <= x && y <= hi)
		return seg[node];
	int mid = (x + y) >> 1;
	int left = query(lo, hi, node * 2, x, mid);
	int right = query(lo, hi, node * 2 + 1, mid + 1, y);
	return left + right;
}
int update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y) return seg[node];
	if (x == y) return seg[node] = val;
	int mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}
int main() {
	scanf("%d", &n);
	pos.resize(n);
	seg.resize(n * 4);
	for (int tmp, i = 0; i < n; i++){
		scanf("%d", &tmp);
		pos[tmp-1] = i;
	}
	init(1, 0, n - 1);
	int s = 0;
	int e = 1;
	for (int i = 0; i < n; i++) {
		if (i % 2==0) {
			printf("%d\n", query(0, pos[s], 1, 0, n - 1)-1);
			update(pos[s], 0, 1, 0, n - 1);
			s++;
		}
		else {
			printf("%d\n", query(pos[n - e], n - 1, 1, 0, n - 1) - 1);
			update(pos[n - e], 0, 1, 0, n - 1);
			e++;
		}
	}


	return 0;
}