#include<cstdio>
#include<vector>
#include<algorithm>
#define INF 1000000001
using namespace std;
int n, m, a, b, p, q, sz;
struct node {
	int val;
	node* left;
	node* right;
	node(int v, node* le, node* ri) {
		val = v;
		left = le;
		right = ri;
	}
	node* update(int x, int y, int pos) {
		if (x <= pos&&pos <= y) {
			if (x == y) return new node(val + 1, NULL, NULL);
			int mid = (x + y) >> 1;
			return new node(val + 1, left->update(x, mid, pos), right->update(mid + 1, y, pos));
		}
		else return this;
	}
};
vector<node*>seg;
int query(node *v, int x, int y, int k) {
	if (v == NULL)return 0;
	if (y <= k) return 0;
	if (x > k)return v->val;
	int mid = (x + y) >> 1;
	return query(v->left, x, mid, k) + query(v->right, mid + 1, y, k);
}
int main() {
	scanf("%d", &n);
	seg.resize(n + 1);

	seg[0] = new node(0, NULL, NULL);
	seg[0]->left = seg[0]->right = seg[0];
	for (int tmp ,i = 0; i < n; i++) {
		scanf("%d", &tmp);
		seg[i + 1] = seg[i]->update(1,INF, tmp);
	}
	scanf("%d", &m);
	int last = 0;
	for (int u,v,k, i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &k);
		u ^= last;
		v ^= last;
		k ^= last;
		last = query(seg[v], 1, INF, k) - query(seg[u - 1], 1, INF, k);
		printf("%d\n", last);
	}

	return 0;
}