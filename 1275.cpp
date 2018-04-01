#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
int n, q;
int x, y, a, b;
int val;
ll seg[400000];
ll query(int low, int hig, int node, int x, int y) {
	if (low > y || hig < x)
		return 0;
	if (low <= x &&y <= hig) return seg[node];

	int mid = (x + y) >> 1;
	return  query(low, hig, node*2, x, mid) + query(low, hig, node * 2 + 1, mid + 1, y);


}

ll update(int pos,int val, int node, int x, int y) {
	if (pos < x || pos >y) return seg[node];
	if (x == y) return seg[node] = (ll)val;
	int mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		update(i, val, 1, 0, n - 1);
	}
	while (q--) {
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if (x > y) swap(x, y);
		printf("%lld\n", query(x-1, y-1, 1, 0, n - 1));
		update(a - 1, b, 1, 0, n - 1);
	}
	return 0;
}