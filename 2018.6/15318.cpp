#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll> a, psum, b;
int n;
int main() {
	scanf("%d", &n);
	a.resize(n + 1), psum.resize(n + 1), b.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if (i % 2 == 0)
			b[1] = (b[1] + -1 * i*a[i]), psum[i] = psum[i - 1] + -1 * a[i];
		else
			b[1] = (b[1] + i*a[i]), psum[i] = psum[i - 1] + a[i];
	}
	ll p = b[1];
	ll q = 0;
	for (int i = 2; i <= n; i++) {
		if (!(i & 1))
			p = -(p - (psum[n] - psum[i - 2]));
		else
			p = -(p + psum[n] - psum[i - 2]);

		if (n % 2==0) {
			if (i % 2 == 0)
				q = -(q - psum[i - 2]);
			else
				q = -(q + psum[i - 2]);
		}
		else {
			if (i % 2 == 0)
				q = -(q + psum[i - 2]);
			else
				q = -(q - psum[i - 2]);
		}
		if (n & 1) q += a[i - 1] * n;
		else q += -a[i - 1] * n;
		b[i] = p + q;
	}
	for (int i = 1; i <= n; i++) {
		printf("%lld ", b[i]);
	}
	return 0;
}