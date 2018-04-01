#include<iostream>
#include<algorithm>
using namespace std;
int n, m, n1, m1;
int gcd(int a, int b) {
	if (a%b == 0) {
		return b;
	}
	else return gcd(b,a%b);
}
int main() {
	scanf("%d %d\n%d %d", &n, &m, &n1, &m1);
	n = n*m1 + n1*m;
	m = m*m1;
	int g = gcd(n, m);

	printf("%d %d", n / g, m / g);
	return 0;
}