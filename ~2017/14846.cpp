#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int psum[11][301][301];
int in[301][301];

int func(int u, int v, int p, int q) {
	if (u > p) swap(u, p);
	if (v > q) swap(v, q);

	int ret = 0;
	for (int i = 1; i <= 10; i++) {
		int tmp = psum[i][p][q] - psum[i][u-1][q] - psum[i][p][v-1] + psum[i][u-1][v-1];
		if (tmp > 0)
			ret++;
	}
	return ret;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <=n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &in[i][j]);
			for (int k = 1; k <= 10; k++) {
				psum[k][i][j] += psum[k][i][j-1]+psum[k][i-1][j]-psum[k][i-1][j-1];
				if (k == in[i][j])
					psum[k][i][j]++;
			}
		}
	}
	int t;
	scanf("%d", &t);
	for (int u,v,p,q, i = 0; i < t; i++) {
		scanf("%d %d %d %d", &u, &v, &p, &q);
		printf("%d\n", func(u, v, p, q));
	}
	return 0;
}