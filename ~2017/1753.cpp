#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 987654321
using namespace std;
int v, e, s;
int from, to, cost;
vector<pair<int, int>> edge[20001];

vector<int> dijkstra(int src) {
	vector<int>dist(v + 1, INF);//왜 v+1?? v개면 되는거 아닌가?
	dist[src] = 0;// 자기 자신으로 가는거니까 0
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src)); //cost, 현위치

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue; //이미 가는데 든 비용이 현재점 에서 가는 비용보다 싸면 현제 간 값은 필요 없음
		for (int i = 0; i < edge[here].size(); i++) {
			//현재 자기와 연결된 간선들 다 가기
			int there = edge[here][i].first;
			int nextDist = cost + edge[here][i].second;

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}


int main() {
	scanf("%d %d\n%d", &v, &e, &s);
	
	while (e--) {
		scanf("%d %d %d", &from, &to, &cost);
		edge[from].push_back({ to, cost });
	}

	vector<int>	 result;
	result = dijkstra(s);
	for (int i = 1; i < result.size(); i++) {
		if (result[i] == INF) {
			printf("INF\n");
			continue;
		}
		else printf("%d\n", result[i]);
	}
	return 0;
}