#include<cstdio>
#include<map>	
#include<queue>
using namespace std;
map<int, priority_queue<int>> ma;
priority_queue<pair<int, priority_queue<int>*>> pq;
priority_queue<int>* x;
int n, ans;
int main() {
	scanf("%d", &n);
	for (int t, c, i = 0; i < n; i++) {
		scanf("%d %d", &t, &c);
		ma[t].push(c);
	}
	auto t = ma.end();
	t--;
	auto fuck = t;
	for (int i = t->first; i > 0; i--) {
		if (fuck != --ma.begin() && i == fuck->first) {
			pq.push({ fuck->second.top(), &fuck->second }), fuck--;
		}
		if (pq.empty())
			continue;
		ans += pq.top().first;
		x = pq.top().second;
		x->pop();
		pq.pop();
		if (!x->empty()) {
			pq.push({ x->top(), x });
		}
	}
	printf("%d\n", ans);
	return 0;
}