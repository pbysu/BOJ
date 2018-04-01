#include<iostream>
#include<algorithm>
#include<vector>
#define INF 18446744073709551610
using namespace std;
typedef unsigned long long ull;
ull maxSeg[400000];
ull minSeg[400000];
vector<int> a;
int n, m;
int val;

ull maxUpdate(int pos, int val, int node, int x, int y) {
	if (pos < x || y < pos) return maxSeg[node];

	if (x == y) return maxSeg[node] = val;

	int mid = (x + y) >> 1;
	ull leftChildVal = maxUpdate(pos, val, node * 2, x, mid);
	ull rightChildVal = maxUpdate(pos, val, node * 2 + 1, mid + 1, y);
	return maxSeg[node] = max(leftChildVal, rightChildVal);
}

ull minUpdate(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y) return minSeg[node];
	if (x == y) return minSeg[node] = val;
	int mid = (x + y) >> 1;

	ull leftChildVal = minUpdate(pos, val, node * 2, x, mid);
	ull rightChildVal = minUpdate(pos, val, node * 2 + 1, mid + 1, y);

	return minSeg[node] = min(leftChildVal, rightChildVal);
}


ull maxQuery(int low, int hig, int node, int x, int y) {
	if (y < low || x > hig) return -INF;
	if (y <= hig && x >= low) return maxSeg[node];

	int mid = (x + y) >> 1;

	ull leftChildVal = maxQuery(low, hig, node * 2, x, mid);
	ull rightChildVaL = maxQuery(low, hig, node * 2 + 1, mid + 1, y);
	return max(leftChildVal, rightChildVaL);
}

ull minQuery(int low, int hig, int node, int x, int y) {
	if (y < low || hig < x) return INF;

	if (y <= hig && x >= low) return minSeg[node];
	int mid = (x + y) >> 1;
	ull leftChildVal = minQuery(low, hig, node * 2, x, mid);
	ull rightChildVaL = minQuery(low, hig, node * 2 + 1, mid + 1, y);
	return min(leftChildVal, rightChildVaL);

}

void init(int node, int x, int y) {
	if (x == y) {
		maxSeg[node] = a[x];
		minSeg[node] = a[x];
	}

	else {
		int mid = (x + y) >> 1;
		init(node * 2, x, mid);
		init(node * 2 + 1, mid + 1, y);
		maxSeg[node] = max(maxSeg[node * 2], maxSeg[node * 2 + 1]);
		minSeg[node] = min(minSeg[node * 2], minSeg[node * 2 + 1]);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	int s, e;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	init(1, 0, n - 1);

	for (int i = 0; i < m; i++) {

		scanf("%d %d", &s, &e);

		if (s > e) swap(s, e);

		printf("%llu %llu\n",
			minQuery(s - 1, e - 1, 1, 0, n - 1), maxQuery(s - 1, e - 1, 1, 0, n - 1));
	}
	return 0;
}