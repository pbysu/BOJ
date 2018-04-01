#include<cstdio>
#include<queue>
#define mod 1000000007
using namespace std;
typedef long long ll;
int t, n;
ll tmp = 1;
int main() {
	scanf("%d", &t);
	priority_queue<ll> pq;
	while (t--) {
		scanf("%d", &n);
		
		for (int i = 0; i < n; i++) {
			scanf("%lld", &tmp);
			pq.push(-tmp);
		}

		tmp = 1;
		ll ans = 1;
		while (pq.size() > 1) {
			tmp = pq.top();
			pq.pop();
			tmp = (tmp*pq.top());
			pq.pop();
			ans = (tmp%mod * ans%mod) % mod;
			pq.push(-tmp);
		}
		printf("%lld\n", ans);
		if(!pq.empty())
			pq.pop();
	}
	return 0;
}