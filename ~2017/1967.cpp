#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, from, to, cost;
bool visited[10001];
vector<vector<pair<int, int>>> v;

int bfs(int src) {
	queue<pair<pair<int, int>,int>> q;
	
	q.push({ { src, 0 },-1});
	int ret = 0;

	while (!q.empty()) {
		int pos = q.front().first.first;
		int cost = q.front().first.second;
		int ex = q.front().second;
		q.pop();

		ret = max(cost, ret);

		for (int i = 0; i < v[pos].size(); i++) {
			int next = v[pos][i].first;
			if (ex == next) continue;
			int val = v[pos][i].second;
			q.push({ { next,cost + val }, pos});
		}

	}

	return ret;
}

int main() {
	scanf("%d", &n);
	v.resize(n + 1);
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		v[from].push_back({to, cost});
		v[to].push_back({ from, cost });
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ret = max(bfs(i), ret);
	}
	printf("%d\n", ret);

	return 0;
}