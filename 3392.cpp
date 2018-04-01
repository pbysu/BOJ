#include<iostream>
#include<algorithm>
#include<vector>
#define LIM 120000
#define xxx 30000
using namespace std;
int seg[LIM];
int statue[LIM];
typedef long long ll;
struct pos {
	int x;
	int lo;
	int hi;
	int start;
};
vector<pos> line;
int n;
int update(int lo, int hi, int val, int node, int x, int y) {
	if (lo > y || hi < x)return seg[node];
	if (lo <= x&&y <= hi) {
		statue[node] += val;
		if (statue[node])
			return seg[node] = y - x + 1;
		else {
			if (x == y) return seg[node] =0;
			return seg[node] = seg[node * 2] + seg[node * 2 + 1];
		}
	}
	int mid = (x + y) >> 1;
	seg[node] = update(lo, hi, val, node * 2, x, mid) + update(lo, hi, val, node * 2 + 1, mid + 1, y);
	if (statue[node]) return seg[node] = y - x + 1;
	return seg[node];
}
int main() {
	scanf("%d", &n);
	line.resize(n * 2);
	for (int a, b, c, d, k = 0, i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		line[k++] = { a, b,d - 1, 1 };
		line[k++] = { c - 1,b,d - 1, -1 };
	}
	sort(line.begin(), line.end(), [](pos p1, pos p2) {
		return p1.x < p2.x;
	});
	int lo, hi, pos, ex, len;
	ll ret = 0;
	ex = line[0].x;
	update(line[0].lo, line[0].hi, 1, 1, 0, xxx);
	for (int i = 1; i < line.size(); i++) {
		lo = line[i].lo;
		hi = line[i].hi;
		pos = line[i].x;
		if (line[i - 1].start == -1 && line[i].start == 1)len = pos - ex - 1;
		else if (line[i - 1].start*line[i].start == 1) len = pos - ex;
		else len = pos - ex + 1;
		ret += ((ll)len)*(seg[1]);
		update(lo, hi, line[i].start, 1, 0, xxx);
		ex = pos;
	}
	printf("%lld\n", ret);
	return 0;
}