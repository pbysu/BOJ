#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int t, n;
vector<int> adj;
vector<pair<int,int>> discover;
int cnt = 0;
int team = 0;
int tmp = 1;
int allDfs(int pos, int cnt) {
	discover[pos].first = tmp;
	discover[pos].second = cnt;

	int next = adj[pos];
	if (discover[next].first == 0)
		return allDfs(next, cnt + 1);
	else if (discover[next].first == tmp) {
		return 1+discover[pos].second - discover[next].second;
	}
	
	else return 0;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		team = 0;
		cnt = 0;
		discover.clear();

		discover.resize(n+1);
		adj.resize(n + 1);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &adj[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (discover[i].first == 0) {
				team +=allDfs(i, 1);
				tmp++;
			}
				
		}
		printf("%d\n", n-team);
	}

	return 0;
}