#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node {
	node* left;
	node* right;
	int cnt;
	node(int c, node* l, node* r) {
		cnt = c;
		left = l;
		right = r;
	}
	node* update(int x, int y, int pos) {
		if (x <= pos&&pos <= y) {
			if (x == y) return new node(1, NULL, NULL);
			int mid = (x + y) >> 1;
			return new node(cnt + 1, left->update(x, mid, pos), right->update(mid + 1, y, pos));
		}
		else
			return this;
	}
};
vector<node*> seg;
int n, m, tmp, u, v,k, uv, puv, sz;
vector<int> r, in;
void dfs(int here, int parent) {
	seg[here] = seg[parent]->update(1, sz, lower_bound(r.begin(), r.end(), in[here-1]) - r.begin() + 1);
	if (here < n) {
		dfs(here + 1,here);
	}
}

int query(node* u, node* v, node* uv, node* puv, int x, int y, int k) {
	if (x == y)
		return x;
	int c = u->left->cnt + v->left->cnt - uv->left->cnt- puv->left->cnt;
	int mid = (x + y) >> 1;
	if (c >= k) return query(u->left, v->left, uv->left, puv->left, x, mid, k);
	return query(u->right, v->right, uv->right, puv->right, mid + 1, y, k - c);
}
int main() {

	scanf("%d %d", &n, &m);
	r.resize(n);
	in.resize(n);
	seg.resize(n+1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
		r[i] = in[i];
	}
	sort(r.begin(), r.end());
	sz = r.size();
	seg[0] = new node(0, NULL, NULL);
	seg[0]->left = seg[0]->right = seg[0];
	dfs(1, 0);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &k);
		uv = min(u, v);
		puv = uv - 1;
		printf("%d\n", r[query(seg[u], seg[v], seg[uv], seg[puv], 1, n, k)-1]);
	}

	return 0;
}