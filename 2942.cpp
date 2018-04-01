#include<cstdio>
#include<algorithm>

using namespace std;
int n, m;
int gcdf(int n, int m) {
	if (m == 0)return n;
	else gcdf(m, n%m);
}
int main() {
	scanf("%d %d", &n, &m);
	int gcd = gcdf(n, m);

	for (int i = 1; i <= gcd; i++) {
		if (gcd%i==0)
			printf("%d %d %d\n", i, n / i, m / i);
	}
	return 0;
}