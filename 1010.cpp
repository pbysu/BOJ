#include<iostream>
#include<algorithm>

using namespace std;

typedef unsigned long long ll;
ll dp[31];
ll t, n, r;

ll factori(ll t) {
	

	ll &ret = dp[t];
	if (t < 1) return ret= 1;

	if (ret != 0)
		return ret;

	 return ret = t*factori(t - 1);
}


ll nfactori(ll x) {
	if (x < (n-r) + 1)
		return 1;
	return x*nfactori(x-1);
}

int main() {
	ll ans = 0;
	scanf("%llu", &t);

	while (t--) {
		scanf("%llu %llu", &r, &n);
		r = r > n - r ? n - r : r;
		ans = nfactori(n) / (factori(r));

		printf("%lld\n", ans);
	}

	return 0;
}