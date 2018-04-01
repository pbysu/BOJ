#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;
int t, n, m, sccCnt, rootNum;
vector<vector<int>> adj;
vector<int> check;
vector<int> root;
stack<int> s;
int allDfs(int pos) {
	root[pos] = ++rootNum;
	int ret = root[pos];
	s.push(pos);
	for (int next : adj[pos]) {
		if (root[next] == 0) ret = min(ret, allDfs(next));
		else if (!check[next]) ret = min(ret, root[next]);
	}
	if (ret == root[pos]) {
		int tmp;
		sccCnt++;
		while (true) {
			tmp = s.top();
			s.pop();
			check[tmp] = sccCnt;
			if (tmp == pos) break;
		}
	}
	return ret;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		adj.clear();
		check.clear();
		root.clear();

		adj.resize(n + 1);
		check.resize(n + 1);
		root.resize(n + 1);
		sccCnt = 0;
		rootNum = 0;

		for (int u, v, i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
		}

		for (int i = 1; i <= n; i++) {
			if (!check[i]) allDfs(i);
		}
			
		
		vector<int> indegree(sccCnt+1);

		for (int i = 1; i <= n; i++) {
			for (int j : adj[i]) {
				if (check[i] != check[j]) {
					indegree[check[j]]++;
				}
			}
		}
		int ret = 0;
		for (int i = 1; i <= sccCnt; i++) {
			if (indegree[i] == 0)ret++;
		}
		printf("%d\n", ret);
	}
	return 0;
}