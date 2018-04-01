#include<iostream>
#include<algorithm>

using namespace std;

long long gcd(long long p, long long q) {
	if (q == 0) return p;
	else gcd(q, p %q);
}
int main() {

	long long n, m;
	cin >> n>> m;
	long long p, q;
	long long temp1 = sqrt(n);
	long long temp2 = sqrt(m);
	p = temp2 - temp1;
	q = m - n;
	long long gc = gcd(p, q);
	if (p == 0)
		printf("0");
	else printf("%lld/%lld", p/gc, q/gc);
	
}