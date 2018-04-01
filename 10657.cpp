#include<cstdio>
int n, table[100001][2];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &table[i][0], &table[i][1]);
	int speed = 2e9;
	int pos;
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (speed >= table[i][1]) {
			ans++; speed = table[i][1]; continue;
		}
	}
	printf("%d", ans);
	return 0;
}