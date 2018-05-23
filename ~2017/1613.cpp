#include<iostream>
#include<vector>
using namespace std;
vector<bool> visited;
bool flo[401][401];
int n, m;
int main() {
	scanf("%d %d", &n, &m);

	for (int u, v, i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		--u, --v;
		flo[u][v] = 1;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (!flo[i][k])continue;
			for (int j = 0; j < n; j++) {
				if (flo[k][j]) flo[i][j] = true;
			}
		}
	}
	scanf("%d", &m);
	for (int u,v,i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		u--; v--;
		if (flo[u][v] && flo[v][u])
			printf("0");
		else if ((flo[u][v] || flo[v][u]) == false)
			printf("0");
		else if (flo[u][v])
			printf("-1");
		else
			printf("1");
		printf("\n");
	}
	return 0;
}