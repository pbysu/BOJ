#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF = 2147483647;
ll l, r, m, ret;
ll n, a, b, c;
struct Val {
	ll a, b, c;
	Val() { a = b = c = 0; }
	void set(ll a, ll c, ll b) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
}val[20010];

ll check(ll m) {
	ll lim, ret;
	ret = 0;
	for (int i = 0; i < n; i++) {
		if (m >= val[i].a) {
			lim = min(val[i].c, m);
			ret += (lim - val[i].a) / val[i].b + 1;
		}
	}
	return ret;
}

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld %lld", &a, &c, &b);
		val[i].set(a, c, b);
	}
	l = 0;r = INF;
	while (l < r) {
		m = (l + r) >> 1;
		if (check(m)&1) {
			r = m;
		}
		else {
			l = m+1;
		}
	}
	if (l == INF) {
		printf("NOTHING\n");
	}
	else {
		printf("%lld %lld\n", l, check(l) - check(l - 1));
	}
	return 0;
}