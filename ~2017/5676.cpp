#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int n, k;
vector<int>seg;

int update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y) return seg[node];
	if (x == y)
		return seg[node] = val;

	int mid = (x + y) >> 1;

	int left = update(pos, val, node * 2, x, mid);
	int right = update(pos, val, node * 2 + 1, mid + 1, y);

	return seg[node] = left * right;
}

int query(int lo, int hi, int node, int x, int y) {
	if (hi<x || lo>y) return 1;
	if (lo <= x&&y <= hi) return seg[node];

	int mid = (x + y) >> 1;

	int left = query(lo, hi, node * 2, x, mid);
	int right = query(lo, hi, node * 2 + 1, mid + 1, y);

	return left * right;
}

int main() {
	while (scanf("%d %d", &n, &k)!= EOF) {
		int temp;
		string str;
		char a;
		int b, c;
		seg.resize(n * 4);
		fill(seg.begin(), seg.end(), 1);

		for (int i = 0; i < n; i++) {
			cin >> str;
			temp = stoi(str);
			if(temp>0) update(i, 1, 1, 0, n - 1);
			else if(temp<0)  update(i, -1, 1, 0, n - 1);
			else if (temp == 0) update(i, 0, 1, 0, n - 1);
		}

		for (int i = 0; i < k; i++) {
			getchar();
			scanf("%c %d %d", &a, &b, &c);

			if (a == 'C') {
				if (c>0) update(b-1, 1, 1, 0, n - 1);
				else if (c<0)  update(b-1, -1, 1, 0, n - 1);
				else if (c== 0) update(b-1, 0, 1, 0, n - 1);
			}
			else if(a=='P'){
				temp = query(b - 1, c - 1, 1, 0, n - 1);
				if (temp < 0)printf("-");
				else if (temp > 0) printf("+");
				else printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}