#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll x, y, w, s, ans;
int main() {
	scanf("%lld %lld %lld %lld", &y, &x, &w, &s);
	y = abs(y);
	x = abs(x);
	if (x > y) swap(y, x);
	ans = min((x + y)*w ,(y - x)*w + x*s );
	ll tmp = 0;

	if ((y - x) % 2) {
		y--;
		tmp = w;
	}
	ll a = y - x;
	tmp += a*s + (y-a)*s;
	ans = min(ans, tmp);
	printf("%lld", ans);
}