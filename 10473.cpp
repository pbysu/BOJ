#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#include<cmath>
#define INF 1e9
using namespace std;

struct pos {
	double x, y;
};
vector<pos> in;
vector<vector<pair<int, double>>> adj;
double sx, sy, ex, ey, v = 5;
int n;

double dijkstra() {
	vector<double> dij(n+2, INF);
	priority_queue<pair<int, double>> q;
	q.push({ 0,0 });
	dij[0] = 0;
	while (!q.empty()) {
		int cur = q.top().first;
		double cost = -q.top().second;
		q.pop();
		for (pair<int, double> next : adj[cur]) {
			int there = next.first;
			double plusCost = cost + next.second;
			if (dij[there] > plusCost) {
				dij[there] = plusCost;
				q.push({ there, -plusCost });
			}
		}
	}
	return dij[n + 1];
}
double distance(pos p, pos q) {
	return sqrt(pow((p.x - q.x), 2) + pow((p.y - q.y), 2));
}
int main() {
	scanf("%lf%lf%lf%lf", &sx, &sy, &ex, &ey);
	scanf("%d", &n);
	adj.resize(n + 2);
	in.resize(n + 2);
	in[0].x = sx;
	in[0].y = sy;
	in[n + 1].x = ex;
	in[n + 1].y = ey;
	for (int i = 1; i <= n; i++) {
		scanf("%lf %lf", &in[i].x, &in[i].y);
	}

	for (int i = 1; i <= n + 1; i++) {
		adj[0].push_back({ i,distance(in[i], in[0])/v});
		for (int j = i + 1; j <= n + 1; j++) {
			double dis = distance(in[i], in[j]);
			double time = dis / v;
			double useFire = dis >= 50 ? (dis - 50) / v + 2 : 2 + (50 - dis) / v;
			time = min(useFire, time);
			adj[i].push_back({ j, time });
			adj[j].push_back({ i, time });
		}
	}
	printf("%lf\n", dijkstra());

	return 0;
}