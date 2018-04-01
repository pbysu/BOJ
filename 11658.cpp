#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int bit[(1 << 10) + 1][(1 << 10) + 1];
int n, m, tmp;
void update(int r, int c, int val) {
	for (int i = r; i <= n; i += (i&-i)) {
		for (int j = c; j <= n; j += (j&-j)) {
			bit[i][j] += val;
		}
	}
}
int sum(int r, int c) {
	int ret = 0;
	for (int i = r; i >0; i -= (i &-i)) {
		for (int j = c; j > 0; j-=(j&-j)) {
			ret += bit[i][j];
		}
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &tmp);
			update(i, j, tmp);
		}
	}

	for (int st,r,c,p,q,v, i = 0; i < m; i++) {
		scanf("%d", &st);
		if (st == 0) {
			scanf("%d %d %d", &r, &c, &v);
			int curVal = sum(r, c) - sum(r - 1, c) - sum(r, c - 1) + sum(r - 1, c - 1);
			update(r, c, v - curVal);
		}
		else {
			scanf("%d %d %d %d", &r, &c, &p, &q);
			if (r > p)swap(r, p);
			if (c > q)swap(c, q);
			printf("%d\n", sum(p, q) - sum(r - 1,q) - sum(p, c - 1) + sum(r-1, c-1));
		}
	}
}