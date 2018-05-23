#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll seg[4000000];
int n;
int tc;
int a, c;
ll b;
ll update(int pos, ll val, int node, int x, int y) {
	if (pos<x || pos>y) return seg[node];
	if (x == y) return seg[node] += val;
	int mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);

}

ll query(ll val, int node, int x, int y) {
	if (x == y) {
		printf("%d\n", x+1);
		return update(x,-1,1,0,999999);
	}
	int mid = (x + y) >> 1;
	if (val > seg[node * 2]) return query(val - seg[node*2], node * 2 + 1, mid+1, y);
	else return query(val, node * 2, x, mid);
}

int main() {
	scanf("%d", &n);

	tc = n;
	while (tc--) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%lld", &b);
			query(b, 1, 0, 999999);
		}
		else {
			scanf("%d %lld", &c, &b);
			update(c - 1, b, 1, 0, 999999);
		}
	}
	return 0;
}