#include<iostream>
#include<cmath>

using namespace std;
typedef unsigned long long ll;
ll val[50];
int main() {
	ll a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	ll ret = 1;
	a = a%c;
	while(b>0){
		if (b % 2) {
			ret *= a;
			ret %= c;
		}
		a *= a;
		a %= c;
		b /= 2;
	}
	printf("%lld", ret);
	return 0;
}