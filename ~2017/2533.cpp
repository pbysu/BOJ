#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define INF 987654321
using namespace std;
vector<vector<int>> adj;
int n;
int even, odd;
int dp[1000010][2];
int check[1000010];
int func(int pos,int statue) {
	int & ret = dp[pos][statue];
	if (ret != -1) return ret;
	
	check[pos] = true;
	if (statue == 1) {
		ret = 1;
		for (int next : adj[pos]) {
			if (!check[next]) {
				ret += min(func(next, 0), func(next, 1));
			}
		}
	}
	else {
		ret = 0;
		for (int next : adj[pos]) {
			if (!check[next]) {
				ret += func(next, 1);
			}
		}
	}
	check[pos] = false;
	return ret;
}
int main() {
	scanf("%d", &n);
	adj.resize(n + 1);
	memset(dp, -1, sizeof(dp));
	for (int u,v, i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ret = min(func(1,0), func(1,1));
	printf("%d",ret);
	return 0;
}