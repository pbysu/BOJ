#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;

queue<int> qAns;
int tc, n, m, val;
int seg[800010];
int pos[100001];

int update(int pos, int val, int node, int x, int y) {
	
	if (x > pos || pos > y) return seg[node];
	if (x == y) return seg[node] = val;

	int mid = (x + y) >> 1;

	return seg[node] = update(pos, val, node * 2, x, mid)
		+ update(pos, val, node * 2 + 1, 1+mid, y);
}

int query(int lo, int hi, int node, int x, int y) {
	if (lo > y || hi < x) return 0;
	if (lo <= x && hi >= y) return seg[node];
	int mid = (x + y) / 2;
	return query(lo, hi, node * 2, x, mid) 
		+ query(lo, hi, node * 2 + 1, mid + 1, y);
}


int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		int lim = n+m - 1;

		for (int i = 0; i < n; i++) {
			update(i, 1, 1, 0, lim);
			pos[i + 1] = n-1-i;
		}
		int k = n;
		for (int i = 0; i < m; i++) {
			scanf("%d", &val);

			qAns.push(query( pos[val],lim, 1, 0, lim)-1);
			update(pos[val], 0, 1, 0, lim);
			pos[val] = k;
			k++;
			update(pos[val], 1, 1, 0, lim);

		}
		while (!qAns.empty()) {
			printf("%d ", qAns.front());
			qAns.pop();
		}

		printf("\n");
		for (int i = 1; i <= 4*lim; i++) {
			seg[i] = 0;
		}

	}


	return 0;
}