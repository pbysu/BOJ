#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#define INF 1e9
using namespace std;
int visited[250002];
int n, m;
int func(int s, int t) {
	memset(visited, -1, sizeof(visited));
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s});

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (visited[here] != -1)continue;
		visited[here] = cost;
		if (here == t) break;
		cost++;

		int there = here - 1;
		if (there >= 0 && visited[there] ==-1) {
			pq.push({ -cost,there });
		}
		there = here + 1;

		if (there <= 100000 && visited[there] ==-1) {
			pq.push({ -cost,there });
		}
		there = here * 2;
		cost -= 1;
		if (there <= 250000 && visited[there] ==-1) {
			pq.push({ -cost,there });
		}
	}
	return visited[t];
}

int main() {
	scanf("%d %d", &n, &m);
	printf("%d\n", func(n, m));
	return 0;
}