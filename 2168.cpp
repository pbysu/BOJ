#include<iostream>
using namespace std;
int n, m;
int gcd(int a, int b) { return  a%b == 0 ? b : gcd(b, a%b); }
int main() {
	scanf("%d %d", &n, &m);
	int l = gcd(n, m);
	printf("%d",( n / l + m / l - 1)*l);
	return 0;
}