#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> seg;
vector<int> ans;
int n;

int update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y) return seg[node];
	if (x == y) return seg[node] = val;
	
	int mid = (x + y) >> 1;

	int left = update(pos, val, node * 2, x, mid);
	int right = update(pos, val, node * 2 + 1, mid + 1, y);

	return seg[node] = left + right;
}

int query(int val, int node,int idx, int x, int y) {
	if (x == y) {
		ans[x] = idx;
		return update(x, 0, 1, 0, n - 1);
	}
	int mid = (x + y) >> 1;

	if (seg[node * 2] < val)
		return query(val - seg[node * 2], node * 2 + 1, idx, mid+1, y);

	else
		return query(val, node * 2, idx, x, mid);
}

int main() {

	scanf("%d", &n);
	ans.resize(n);
	seg.resize(4*n);
	int temp;

	for (int i = 0; i < n; i++) {
		update(i, 1, 1, 0, n - 1);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		query(temp+1, 1, i+1, 0, n - 1);
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", ans[i]);
	}


	return 0;
}