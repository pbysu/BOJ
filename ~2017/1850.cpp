#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
ull a, b;
ull gcd(ull a, ull b) {
	if (a%b == 0)
		return  b;
	else
		return 	gcd(b, a%b);
}
int main() {
	scanf("%lld %lld", &a, &b);
	ull sz = gcd(a, b);
	while (sz--)printf("1");
	
	return 0;
}