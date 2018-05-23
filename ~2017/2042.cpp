#include <iostream>
#include <algorithm>

using namespace std;
long long seg[4000000];
//io 시작 hi 는 끝 현재 세그의 위치 초기배열의 시작 초기배열의 끝
long long query(int lo, int hi, int node, int x, int y) {
	//기저조건
	if (lo > y || hi < x) return 0; //밖의 구간
	if (lo <= x && hi >= y) return seg[node]; //안의 구간

	int mid = (x + y) / 2;

	long long left = query(lo, hi, node * 2, x, mid);
	long long right = query(lo, hi, node * 2 + 1, mid + 1, y);

	return left + right;
}
long long update(int pos, long long val, int node, int x, int y) { //값의 갱신
	if (x > pos || y < pos) return seg[node];//base case
	if (x == y) return seg[node] = val;


	int mid = (x + y) >> 1;

	long long left = update(pos, val, node * 2, x, mid);
	long long right = update(pos, val, node * 2 + 1, mid + 1, y);

	return seg[node] = left + right;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0, a; i < n; i++) {
		cin >> a;
		update(i, a, 1, 0, n - 1);
	}

	for (int a, b, c, i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b - 1, c, 1, 0, n - 1);
		}
		else if (a == 2) {
			cout << query(b - 1, c - 1, 1, 0, n - 1) << '\n';
		}
	}

	return 0;
}