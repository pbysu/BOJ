#include<cstdio>

int n, m, in[101];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}
int main() {
	scanf("%d", &n);
	while (n--) {
		long long ans = 0;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &in[i]);
		}

		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				ans += gcd(in[i], in[j]);
			}
		}

		printf("%lld\n", ans);
	}
}