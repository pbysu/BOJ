#include<cstdio>
#include<algorithm>

using namespace std;

int d[1 << 20][20];
int a[20][20];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = 100000000;
		}
	}

	d[1][0] = 0;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 1; j < n; j++) {
			if (i&(1 << j)) {
				for (int k = 0; k < n; k++) {
					if (k != j && (i&(1 << k)) && a[k][j]) {
						d[i][j] = min(d[i][j], d[i - (1 << j)][k] + a[k][j]);
					}
				}
			}
		}
	}
	int ans = 1000000000;
	for (int i = 1; i < n; i++) {
		if (a[i][0]) {
			ans = min(ans, d[(1 << n) - 1][i] + a[i][0]);
		}
	}
	printf("%d", ans);

	return 0;
}