#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
int n;

ll mod = 1e9 + 7;
int main() {
	scanf("%d", &n);
	ll ans = 0, u, v, mul, tmp, pp, bin;
	for (int i = 0; i < n; i++) {
		scanf("%llu %llu", &u, &v);

		tmp = 1, pp = v - 1, bin = 2;
		mul = u*v%mod;

		while (pp) {
			if (pp & 1) tmp = tmp* bin %mod;
			bin = bin*bin %mod, pp /= 2;
		}
		if (v) ans = (ans + mul*tmp) % mod;
	}
	printf("%lld", ans);
	return 0;
}