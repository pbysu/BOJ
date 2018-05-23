#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#define INF 1e9
using namespace std;
pair<int,int> visited[250002];
stack<int> st;
int n, m;
void func(int s, int t) {
	for (int i = 0; i < 250002; i++) {
		visited[i] = { -1,0 };
	}
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0, {s,s} });
	visited[s].second = s;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second.first;
		int ex = pq.top().second.second;
		pq.pop();

		if (visited[here].first != -1)continue;
		visited[here].first = cost;
		visited[here].second = ex;
		if (here == t) break;
		cost++;

		int there = here - 1;
		if (there >= 0 && visited[there].first == -1) {
			pq.push({ -cost,{there,here } });
		}
		there = here + 1;

		if (there <= 100000 && visited[there].first == -1) {
			pq.push({ -cost,{there,here} });
		}
		there = here * 2;
		cost -= 1;
		if (there <= 250000 && visited[there].first == -1) {
			pq.push({ -cost,{there,here } });
		}
	}
	if(t!=s)st.push(t);

	while (visited[t].second != s) {
		st.push(visited[t].second);
		t = visited[t].second;
	}
	st.push(s);
	printf("%d\n", st.size()-1);
	
	while (!st.empty()) {
		printf("%d ", st.top());
		st.pop();
	}


}

int main() {
	scanf("%d %d", &n, &m);
	func(n, m);
	return 0;
}