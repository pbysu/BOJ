#include<iostream>
#include<algorithm>
#include<queue>
#define INF 1000000001

using namespace std;

typedef long long ll;
priority_queue<int> input;

int seg[400010];
ll sumseg[400010];
ll ans[100010];
int n;

ll supdate(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y) return sumseg[node];
	if (x == y)
		return sumseg[node] = val;

	int mid = (x + y) >> 1;

	ll left = supdate(pos, val, node * 2, x, mid);
	ll right = supdate(pos, val, node * 2 + 1, mid + 1, y);

	return sumseg[node] = left + right;
}

ll squery(int lo, int hi, int node, int x, int y) {
	if (hi<x || lo>y) return 0;
	if (lo <= x&&y <= hi) return sumseg[node];

	int mid = (x + y) >> 1;

	ll left = squery(lo, hi, node * 2, x, mid);
	ll right = squery(lo, hi, node * 2 + 1, mid + 1, y);

	return (left + right);
}

int update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y) return seg[node];
	if (x == y)
		return seg[node] = val;

	int mid = (x + y) >> 1;

	int left = update(pos, val, node * 2, x, mid);
	int right = update(pos, val, node * 2 + 1, mid + 1, y);

	return seg[node] = min(left, right);
}


int query(int lo, int val, int node, int x, int y) {

	if (x == y) {
		return y;
	}

	int mid = (x + y) >> 1;

	int left = INF;
	if (mid >= lo && seg[node * 2] <= val)
		left = query(lo, val, node * 2, x, mid);

	int right = query(lo, val, node * 2 + 1, mid + 1, y);

	return min(left, right);
}

int main() {
	int ex, pos, val, exVal;
	ll total;
	scanf("%d", &n);

	int temp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		input.push(-1 * temp);
		update(i, temp, 1, 0, n - 1);
		supdate(i, 1, 1, 0, n - 1);
	}

	ex = 0; pos = 0; exVal = 0;
	total = 0;

	val = input.top()*-1;
	pos = query(0, val, 1, 0, n - 1);
	total = pos + 1 + squery(0, n - 1, 1, 0, n - 1)*(val - 1);

	supdate(pos, 0, 1, 0, n - 1);
	update(pos, INF, 1, 0, n - 1);
	ex = pos;
	ans[pos] = total;
	exVal = val;
	input.pop();

	for (int i = 1; i < n; i++) {
		val = input.top()*-1;
		if (exVal != val) {
			total += squery(ex, n - 1, 1, 0, n - 1);
			pos = query(0, val, 1, 0, n - 1);
			total += squery(0, pos, 1, 0, n - 1) + squery(0, n - 1, 1, 0, n - 1)*(val - exVal - 1);
		}
		else {
			pos = query(ex, val, 1, 0, n - 1);
			total += squery(ex, pos, 1, 0, n - 1);
		}
		ex = pos;
		exVal = val;
		ans[pos] = total;
		supdate(pos, 0, 1, 0, n - 1);
		update(pos, INF, 1, 0, n - 1);
		input.pop();
	}
	for (int i = 0; i < n; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}