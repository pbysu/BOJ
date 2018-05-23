#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 250003
#define INF 1e9
using namespace std;
int left[MAX * 4], right[MAX * 4];
int table[MAX],n, m;
bool lflag, rflag;
int leftUpdate(int pos, int* ptr,int node, int x, int y, int* seg) {
	if (pos<x || pos>y)return seg[node];
	if (x == y) {
		if (seg[node] != n + 1)
			lflag = true;
		else
			lflag = false;

		seg[node] = ptr-table;
		return seg[node];
	}
	int mid = (x + y) >> 1;
	int left = leftUpdate(pos, ptr, node * 2, x, mid, seg);
	int right = leftUpdate(pos, ptr, node * 2 + 1, mid + 1, y, seg);
	seg[node] = table[left] > table[right] ? left : right;
	return seg[node];
}
int rightUpdate(int pos, int* ptr, int node, int x, int y, int* seg) {
	if (pos<x || pos>y)return seg[node];
	if (x == y) {
		if (seg[node] != n)
			rflag = true;
		else
			rflag = false;
		seg[node] = ptr-table;
		return seg[node];
	}
	int mid = (x + y) >> 1;
	int right = rightUpdate(pos, ptr, node * 2, x, mid, seg);
	int left = rightUpdate(pos, ptr, node * 2 + 1, mid + 1, y, seg);
	seg[node] = table[left] > table[right] ? right : left;
	return seg[node];
}

int rQuery(int lo, int hi, int node, int x, int y,int* seg) {
	if (lo > y || hi < x) {
		return MAX - 1;
	}
	if (x <= lo&&hi <= y) {
		return seg[node];
	}
	int mid = (x + y) >> 1;
	int left = rQuery(lo, hi, node * 2, x, mid, seg);
	int right = rQuery(lo, hi, node * 2 + 1, mid + 1, y, seg);
	return table[left] > table[right] ? right : left;
}
int lQuery(int lo, int hi, int node, int x, int y, int* seg) {
	if (lo > y || hi < x) {
		return 0;
	}
	if (x <= lo&&hi <= y) {
		return seg[node];
	}
	int mid = (x + y) >> 1;
	int left = lQuery(lo, hi, node * 2, x, mid, seg);
	int right = lQuery(lo, hi, node * 2 + 1, mid + 1, y, seg);
	return table[left] > table[right] ? left : right;
}
int main() {
	scanf("%d %d", &n, &m);
	table[n+1] = -1;
	table[n] = INF;
	long long ans = 0;
	int tmp;
	fill(right, right + MAX * 4, n);
	fill(left, left + MAX * 4, n + 1);
	int lcnt = 0;
	int rcnt = 0;
	for (int cnt = 0, i = 0; i < n; i++) {
		scanf("%d", &table[i]);
		leftUpdate(i, &table[i], 1, 0, n - 1, left);
		lcnt++;
		cnt++;
		if (cnt == m) {
			while (lcnt + 1 > rcnt) {
				rightUpdate(left[1], &table[left[1]], 1, 0, n - 1, right);
				leftUpdate(left[1], &table[n+1], 1, 0, n - 1, left);
				rcnt++;
				lcnt--;
			}
			while (table[left[1]] > table[right[1]]) {
				tmp = right[1];
				rightUpdate(left[1], &table[left[1]], 1, 0, n - 1, right);
				leftUpdate(left[1], &table[n + 1], 1, 0, n - 1, left);

				leftUpdate(tmp, &table[tmp], 1, 0, n - 1, left);
				rightUpdate(tmp, &table[n], 1, 0, n - 1, right);
			}
			ans += table[right[1]];
			leftUpdate(i - cnt + 1, &table[n + 1], 1, 0, n - 1, left);
			rightUpdate(i - cnt + 1, &table[n], 1, 0, n - 1, right);
			if (lflag)lcnt--;
			else if (rflag)rcnt--;
			lflag = rflag = false;
			cnt--;
		}
	}
	printf("%lld", ans);
	return 0;
}