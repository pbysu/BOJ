#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>	
#include<cstring>
using namespace std;
int tc, n;
typedef long long ll;

struct node {
	int x, y;
};

node *ptr[75000];
ll seg[400000];
node v[100000];
ll update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y) return seg[node];
	if (x == y)
		return seg[node] = val;

	int mid = (x + y) >> 1;

	ll left = update(pos, val, node * 2, x, mid);
	ll right = update(pos, val, node * 2 + 1, mid + 1, y);

	return seg[node] = left + right;
}

ll query(int lo, int hi, int node, int x, int y) {
	if (hi<x || lo>y) return 0;
	if (lo <= x&&y <= hi) return seg[node];

	int mid = (x + y) >> 1;

	ll left = query(lo, hi, node * 2, x, mid);
	ll right = query(lo, hi, node * 2 + 1, mid + 1, y);

	return left+right;
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);

		memset(v, 0, sizeof(v));
		memset(&seg[0], 0, sizeof(seg));
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &v[i].x, &v[i].y);
			ptr[i] = &v[i];
		}

		sort(v, v+n, [](node p, node q) {
			if (p.x != q.x)
				return p.x > q.x;
			else {
				return p.y < q.y;
			}
		});

		sort(ptr, ptr + n, [](node *p, node *q) {
			if (p->y == q->y) {
				return p->x > q->x;
			}
			else
				return p->y < q->y;
		});
	
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			int pos = ptr[i] - &v[0];
			sum += query(0, pos, 1, 0, n - 1);
			update(pos, 1, 1, 0, n - 1);
		}
		printf("%lld\n", sum);
	}

	return 0;
}