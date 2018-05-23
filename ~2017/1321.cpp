#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int n, m;
int c, a;
ll val, b;
ll seg[2000001];
ll input[500001];

ll update(int pos, ll val, int node, int x, int y) {
	if (x > pos || y < pos) return seg[node];

	if (x == y){
		return seg[node] = val;
		}

	int mid = (x + y) >> 1;
	ll leftChilVal = update(pos, val, node * 2, x, mid);
	ll rihgtChilVal = update(pos, val, node * 2 + 1, mid + 1, y);

	return seg[node] = leftChilVal + rihgtChilVal;

 }


int query(ll val, int node, int x, int y) {
	if (x == y )
		return x;
	int mid = (x + y) / 2;
	if (seg[node*2] < val) {
		return query(val-seg[node*2], node * 2+1, mid+1, y);
	}
	else {
		return query(val, node * 2, x, mid);
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &val);
		input[i] = val;
		update(i, val, 1, 0, n-1);
	}
	scanf("%d", &m);

	while (m--) {
		scanf("%d", &c);
		if (c == 1) {
			scanf("%d %lld", &a, &b);
			update(a-1, input[a - 1] + b, 1, 0, n-1);
			input[a - 1] += b;
		}
		else {
			scanf("%lld", &b);
			printf("%d\n",query(b, 1, 0, n - 1)+1);
		}
	}
	return 0;
}