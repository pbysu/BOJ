#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#define MOD 1000000007
using namespace std;
int n;
typedef long long ll;
ll u, v, ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &u, &v);
		ll tmp = 1;
		ll find = 0;
		while (v != 0) {
			if ((v & 1)) {
				find = (find+tmp)%MOD;
			}
			tmp = (tmp*u)%MOD;
			v >>= 1;
		}
		ans =(ans+ find)%MOD;
	}
	printf("%lld", ans);
	return 0;
}