#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int n, m, rootNum, numScc, s, e;
typedef long long ll;
vector<vector<int>> adj;
vector<int> check;
vector<int> root;
vector<pair<int, vector<int>>>allScc;
vector<vector<int>> sccAdj;
stack<int> st;
vector<int>val;
vector<bool> sccRest;
vector<ll> dp;


ll func(int pos) {
	ll &ret = dp[pos];
	if (dp[pos] != -1) return ret;
	ret = 0;
	ll tmp = 0;
	for (int next : sccAdj[pos]) {
		tmp = max(tmp, func(next));
	}
	if (tmp!=0 || sccRest[pos]) {
		return ret =tmp+allScc[pos].first;
	}
	else 
		return (ret = 0);
}
int allDfs(int pos) {
	root[pos] = ++rootNum;
	int ret = root[pos];
	st.push(pos);
	for (int next : adj[pos]) {
		if (root[next] == 0) ret = min(ret, allDfs(next));
		else if (check[next] == 0)ret = min(ret, root[next]);
	}
	if (ret == root[pos]) {
		vector<int> tmp;
		int money = 0;
		numScc++;
		while (true) {
			int t = st.top();
			st.pop();
			money += val[t];
			check[t] = numScc;
			tmp.push_back(t);
			if (t == pos) break;
		}
		allScc.push_back({ money,tmp });
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	adj.resize(n + 1);
	check.resize(n + 1);
	root.resize(n + 1);
	val.resize(n + 1);
	for (int u, v, i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &val[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) allDfs(i);
	}
	sccAdj.resize(numScc);
	sccRest.resize(numScc);
	dp.resize(numScc,-1);
	for (int i = 1; i <= n; i++) {
		for (int next : adj[i]) {
			if (check[i] != check[next]) {
				sccAdj[check[i]-1].push_back(check[next]-1);
			}
		}
	}
	scanf("%d %d", &s, &e);
	for (int k, i = 0; i < e; i++) { scanf("%d", &k); sccRest[check[k]-1] = true; }
	
	printf("%lld", func(check[s] - 1));
	return 0;
}