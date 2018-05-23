#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include <map>
using namespace std;

struct node {
	int cnt = 0;
	node* left;
	node* right;
	node(int cnt, node* left, node* right) {
		this->cnt = cnt;
		this->left = left;
		this->right = right;
	}
	node* update(int x, int y, int pos) {
		if (x <= pos&&pos <= y) {
			if (x == y) return new node(this->cnt + 1, NULL, NULL);
			int mid = (x + y) >> 1;
			return new node(cnt + 1, left->update(x, mid, pos), right->update(mid + 1, y, pos));
		}
		else return this;
	}
};

vector<int> input, ran, height;
vector<vector<int>> adj;
vector<bool> visited;
vector<node*> seg;
vector<vector<int>> p;
int sz, n, m;
int po = 2;
int knt = 2;
int query(node *u, node* v, node* uv, node* root, int x, int y, int k) {
	if (x == y) return x;
	int cnt = u->left->cnt + v->left->cnt - uv->left->cnt - root->left->cnt;
	int mid = (x + y) >> 1;
	if (cnt >= k) return query(u->left, v->left, uv->left, root->left, x, mid, k);
	return query(u->right, v->right, uv->right, root->right, mid + 1, y, k - cnt);
}

int findIdx(int pos) {
	return lower_bound(ran.begin(), ran.end(), pos) - ran.begin() + 1;
}
void dfs(int here, int parent, int depth) {
	seg[here] = seg[parent]->update(1, sz, findIdx(input[here]));
	visited[here] = true;
	height[here] = depth;

	for (int next : adj[here]) {
		if (!visited[next]) {
			p[next][0] = here;
			dfs(next, here, depth + 1);
		}
	}
}
int lca(int  x, int y) {
	if (height[x] > height[y]) swap(x, y);
	for (int i = knt-1; i >= 0; i--) {
		if ((1 << i) <= height[y] - height[x]) {
			y = p[y][i];
		}
	}

	if (x == y)
		return x;
	for (int i = knt-1; i >= 0; i--) {
		if (p[x][i] != p[y][i]) {
			x = p[x][i];
			y = p[y][i];
		}
	}
	return p[x][0];
}
int main() {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	input.resize(n + 1);
	seg.resize(n + 5);
	ran.resize(n);
	adj.resize(n + 1);
	visited.resize(n + 1);
	height.resize(n + 1);

	while(po < n) {
		po *= 2;
		knt++;
	}
	p.resize(n + 1, vector<int>(knt));
	for (int j = 0, i = 1; i <= n; i++, j++) {
		scanf("%d", &input[i]);
		ran[j] = input[i];
	}
	sort(ran.begin(), ran.end());
	ran.erase(unique(ran.begin(), ran.end()), ran.end());
	sz = ran.size();
	for (int u, v, i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	seg[0] = new node(0, NULL, NULL);
	seg[0]->left = seg[0]->right = seg[0];
	dfs(1, 0, 0);
	for (int i = 1; i <knt; i++) {
		for (int j = 1; j <= n; j++) {
			p[j][i] = p[p[j][i - 1]][i - 1];
		}
	}
	for (int u, v, k, i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &k);
		int uv = lca(u, v);
		printf("%d\n", ran[query(seg[u], seg[v], seg[uv], seg[p[uv][0]], 1, sz, k) - 1]);
	}
	return 0;
}