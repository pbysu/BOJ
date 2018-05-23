#include<cstdio>
int n, m;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			printf("=");
		}
		printf("\n");
	}
	return 0;
}