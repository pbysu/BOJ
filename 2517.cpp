#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int> seg;
priority_queue <pair<int,int>> pq;
vector<int> ans;
int n;

int update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y)return seg[node];
	if (x == y)return seg[node] = val;
	int mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid)
		+ update(pos, val, node * 2 + 1, mid + 1, y);
}

int query(int lo, int hi, int node, int x, int y) {
	if (lo > y || hi < x)return 0;
	if (lo <= x && y <= hi)return seg[node];
	int mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) 
		+ query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main() {
	scanf("%d", &n);
	seg.resize(n * 4);
	ans.resize(n);
	for (int tmp, i = 0; i < n; i++) {
		scanf("%d", &tmp);
		pq.push({ tmp, i });
	}

	for (int i = 0; i < n; i++) {
		update(pq.top().second, 1, 1, 0, n - 1);
		ans[pq.top().second] = query(0, pq.top().second, 1, 0, n - 1);
		pq.pop();
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}