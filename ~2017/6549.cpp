#include<iostream>
#include<vector>
#include<algorithm>
#define INF  1000000003
using namespace std;

vector<int> seg;
vector<int>input;
int n, tmp;
typedef long long ll;

int init(int node, int x, int y) {
	if (x == y)return  seg[node] = x;
	int mid = (x + y) >> 1;
	int left = init(node * 2, x, mid);
	int right = init(node * 2 + 1, mid + 1, y);
	return seg[node] = input[left] <= input[right] ? left : right;
}

int query(int lo, int hi, int node, int x, int y) {
	if (hi < x || y < lo) return n;
	if (lo <= x && y <= hi)return seg[node];
	int mid = (x + y) >> 1;
	int left = query(lo, hi, node * 2, x, mid);
	int right = query(lo, hi, node * 2 + 1, mid + 1, y);
	return input[left] <= input[right] ? left : right;
}

ll func(int x, int y) {
	if (y<x || x>y)return 0;
	int idx = query(x, y, 1, 0, n - 1);
	if (idx == n)
		return 0;
	ll ret = (ll)(y-x+1)*input[idx];
	ll left = func(x,idx-1);
	ll right = func(idx+1,y);
	return max(ret, max(left, right));
}

int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			break;
		input.resize(n+1);
		seg.resize(n * 4+4);
		for (int i = 0; i < n; i++) {
			scanf("%d", &input[i]);
		}
		input[n] = INF;
		init(1, 0, n - 1);
		printf("%lld\n", func(0, n - 1));
	}
	return 0;
}