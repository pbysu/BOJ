#include<iostream>
#include<algorithm>
#include<queue>
#define INF 987654321
using namespace std;

int edge[251][251];
int n, m;


int main() {

	scanf("%d %d", &n, &m);

	for (int i = 1; i <=n; i++) {

		for (int j = 1; j <= n; j++) {
			if (i == j) 
				edge[i][j] = 0;
			else
				edge[i][j] = INF;
		}
	}
	int from, to, jd;

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &jd);
		if (jd == 1) {
			edge[from][to] = 0;
			edge[to][from] = 0;
		}
		else {
			edge[from][to] = 0;
			edge[to][from] = 1;
		}
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (edge[i][j] > edge[i][k] + edge[k][j])
					edge[i][j] = edge[i][k] + edge[k][j];
			}
		}
	}

	int tc;
	scanf("%d ", &tc);

	while (tc--) {
		scanf("%d %d", &from, &to);
		if (edge[from][to] ==INF)
			printf("%d\n", 0);
		else {
			printf("%d\n", edge[from][to]);
		}
	}
	return 0;
}