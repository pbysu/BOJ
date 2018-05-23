#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef pair<int, int> p;
int n, m;
vector<vector<int>> adj;
vector<int> discover, fs;
vector<bool> finished;
stack<int> st;
int cnt = 0;

int allDfs(int pos) {
	discover[pos] = ++cnt;
	int ret = discover[pos];
	st.push(pos);

	for (int next : adj[pos]) {
		if (discover[next] == 0) ret = min(ret, allDfs(next));
		else if (!finished[next]) ret = min(ret, discover[next]);
	}

	if (ret == discover[pos]) {
		while (true) {
			int k = st.top();
			st.pop();
			finished[k] = true;
			fs[k] = pos;
			if (pos == k) break;
		}
	}
	return ret;
}
int main() {
	scanf("%d %d", &n, &m);
	int lim = n * 2;
	adj.resize(lim + 1);
	finished.resize(lim + 1);
	fs.resize(lim + 1);
	discover.resize(lim + 1);

	for (int u, v, nu, nv, i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		if (u > 0) nu = u + n;
		else nu = -u, u = -u + n;
		if (v > 0) nv = v + n;
		else nv = -v, v = nv + n;
		adj[nv].push_back(u);
		adj[nu].push_back(v);
	}
	for (int i = 1; i <= lim; i++) {
		if (!discover[i]) allDfs(i);
	}
	for (int i = 1; i <= n; i++) {
		if (fs[i] == fs[i + n]) {
			printf("0");
			return 0;
		}
	}
	printf("1");
	return 0;
}