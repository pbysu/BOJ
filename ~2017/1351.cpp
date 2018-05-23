#include<iostream>
#include<unordered_map>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> ma;

ll n;
int p, q;
ll func(ll num) {
	if (ma[num] != 0)
		return ma[num];
	return ma[num] = func(num / p) + func(num / q);
}
int main() {
	scanf("%lld %d %d", &n, &p, &q);
	ma[0] = 1;
	printf("%lld", func(n));
	return 0;
}