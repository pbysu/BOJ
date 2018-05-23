#include<cstdio>
#include<cstring>

int tc, n, m, tmp;
int sum[101];
int table[101][101];
int flag[101];
int ex[101];
int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);
		memset(sum, 0, sizeof(sum));
		memset(flag, 0, sizeof(flag));
		memset(ex, 0, sizeof(ex));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &table[i][j]);
			}
		}

		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				if (table[i][j] == 0) {
					ex[j]++;
					flag[j]++;
				}
				else if(flag[j]) {
					sum[j] += ex[j];
				}
 			}
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			ans += sum[i];
		}

		printf("%d\n", ans);
	}
}