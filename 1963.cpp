#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
bool prime[10001];
vector<vector<int>> adj;
int n, s, e;
int visited[10001];

int bfs(int s,int v) {
	queue<int> q;
	q.push(s);
	visited[s] = v;
	int cnt = 0;
	while (!q.empty()) {
		cnt++;
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			int cur = q.front();
			q.pop();
			for (int next : adj[cur]) {
				if (visited[next]==v) continue;
				visited[next] = v;
				if (next == e) {
					return cnt;
				}
				else {
					q.push(next);
				}
			}
		}
	}
	return -1;
}
void sieve() {
	int limit = 10000;
	int sqrtLimit = sqrt(limit);
	for (int i = 2; i <= sqrtLimit; i++) {
		if (prime[i]) continue;
		for (int j = i*i; j <= limit; j+=i) {
			prime[j] = true;
		}
	}
}
int main() {
	sieve();
	adj.resize(10000);
	int ex;
	int tmp;
	int dec = 1;
	for (int i = 1000; i < 10000; i++) {
		if (prime[i] == true) continue;
		dec = 1;
		for (int k = 0; k < 4; k++) {
			ex = i%dec;
			dec *= 10;
			tmp = (i / dec)*dec;
			dec /= 10;
			tmp += ex;
			for (int j = 0; j <= 9; ++j) {
				int ttmp =tmp + j*dec;
				if (prime[ttmp] == false) {
					adj[i].push_back(ttmp);
				}
			}
			dec *= 10;
		}
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &s, &e);
		if (s == e) {
			printf("0\n");
			continue;
		}
		int bf = bfs(s,i);

		if (bf == -1) {
			printf("Impossible\n");
		}
		else
			printf("%d\n", bf);
	}
	return 0;
}