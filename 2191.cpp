#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int sink, source, N, M, S, V, a[101], b[101];
typedef pair<double, double> pdd;
vector<pair<double, double>> mouse;
vector<pair<double, double>> house;
vector<vector<int>>adj;
bool visited[101];
double dist(pdd a, pdd b) {
	return sqrt((a.first - b.first)*(a.first - b.first)
		+ (a.second - b.second)*(a.second - b.second));
}


bool dfs(int pos) {
	visited[pos] = true;
	for (int next : adj[pos]) {
		if (!b[next] || !visited[b[next]] && dfs(b[next])) {
			b[next] = pos;
			a[pos] = next;
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d %d %d %d", &N, &M, &S, &V);
	mouse.resize(N+1);
	house.resize(M+1);
	adj.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%lf %lf", &mouse[i].first, &mouse[i].second);
	}
	for (int j = 1; j <= M; j++) {
		scanf("%lf %lf", &house[j].first, &house[j].second);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (dist(mouse[i], house[j]) <= (double)S*V) {
				adj[i].push_back(j);
			}
		}
	}
	int maxMatch = 0;
	for (int i = 1; i <= N; i++) {
		if (a[i] == 0) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) maxMatch++;
		}
	}
	printf("%d\n",N-maxMatch);
	return 0;
}