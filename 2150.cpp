#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;
int n, m, cnt, sccCnt;
vector<vector<int>> adj;
vector<int> discover;
vector<vector<int>> allscc;
vector<bool> scc;
stack<int> s;

int allDfs(int pos) {
	discover[pos] = ++cnt;
	int ret = discover[pos];
	s.push(pos);

	for (int next : adj[pos]) {
		if (discover[next] == 0) ret = min(ret, allDfs(next));
		else if (scc[next] == 0) ret = min(ret, discover[next]);
	}

	if (ret == discover[pos]) {
		vector<int> tmp;
		while (true) {
			scc[s.top()] = true;
			tmp.push_back(s.top());
			if (pos == s.top()) break;
			s.pop();
		}
		sort(tmp.begin(), tmp.end());
		allscc.push_back(tmp);
		s.pop();
		sccCnt++;
	}
	return ret;
}
int main() {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	discover.resize(n + 1);
	scc.resize(n + 1);
	for (int u,v, i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}

	for (int i = 1; i <= n; i++) {
		if (discover[i] == 0)
			allDfs(i);
	}

	printf("%d\n", sccCnt);
	sort(allscc.begin(), allscc.end(), [](vector<int> p, vector<int> q) {
		return p[0] < q[0];
	});
	for (auto r : allscc) {
		for (int pos : r) {
			printf("%d ", pos);
		}
		printf("-1\n");
	}
	return 0;
}