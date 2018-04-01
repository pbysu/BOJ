#include<iostream>
#include<algorithm>
#define INF 987654321
using namespace std;
typedef long long ll;
ll map[110][110];

int main() {
	int n, m;
	scanf("%d\n%d", &n, &m);
	int a, b, c;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (map[a][b]> c) map[a][b] = c;
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}

			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == INF)
				printf("0 ");
			else printf("%lld ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}