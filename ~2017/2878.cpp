#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef unsigned long long ull;
priority_queue <pair<ull,ull>> pq;
ull n, tmp;
ull m, tc, Q, R, ans, diff;
int main() {
	scanf("%llu %llu", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%llu", &tmp);
		pq.push({ tmp,1 });
	}
	pq.push({ 0,0 });
	tc = 0;
	while (n != 0) {
		tmp = pq.top().first; tc = pq.top().second; pq.pop();
		while (pq.top().first == tmp) {
			tc+=pq.top().second;
			pq.pop();
		}
		diff = tmp - pq.top().first; diff *=tc;
		if (diff <= n) {
			n -= diff;
			pq.push({ pq.top().first, tc });
		}
		else {
			Q = n / tc;
			R = n%tc;
			n = 0;
			if(R!=0) pq.push({ tmp - Q - 1,R });
			pq.push({ tmp - Q, tc- R });
		}
	}
	ans = 0;
	while (pq.top().first != 0) {
		ans += pq.top().first*pq.top().first*pq.top().second;
		pq.pop();
	}
	printf("%llu", ans);
	return 0;
}