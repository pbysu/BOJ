#include<iostream>
#include<algorithm>
#include<vector>
#define INF 987654321
using namespace std;
long long n;
vector<long long> in;
vector<pair<long long,long long>> seg;
vector<long long> fs;

pair<long long,long long> query(long long lo, long long hi, long long node, long long x, long long y) {
	if (x > hi || y < lo) return{ INF,INF };
	if (lo <= x&&y <= hi)return seg[node];
	long long mid = (x + y) >> 1;
	pair<long long,long long> left = query(lo, hi, node * 2, x, mid);
	pair<long long,long long> right = query(lo, hi, node * 2 + 1, mid + 1, y);
	return left.first < right.first ? left : right;
}
pair<long long,long long> init(long long node, long long x, long long y) {
	if (x == y) {
		seg[node].first = in[x];
		seg[node].second = x;
		return seg[node];
	}
	long long mid = (x + y) >> 1;
	pair<long long,long long> left = init(node * 2, x, mid);
	pair<long long,long long> right= init(node * 2+1, mid + 1, y);
	return seg[node] = left.first < right.first ? left : right;
}
long long divide(long long x, long long y) {
	if (y<x || x>y)return 0;
	pair<long long, long long> pos = query(x, y, 1, 0, n - 1);
	long long sum = x != 0 ? fs[y] - fs[x - 1] : fs[y];
	long long ret = pos.first*(sum);
	long long left = divide(x, pos.second-1);
	long long right = divide(pos.second+1, y);
	return ret =max(left, max(ret, right));
}
int main() {
	scanf("%lld", &n);
	seg.resize(n * 4);
	fs.resize(n);
	in.resize(n);
	scanf("%lld", &in[0]);
	fs[0] = in[0];
	for (long long i = 1; i < n; i++) {
		scanf("%lld", &in[i]);
		fs[i] = in[i] + fs[i - 1];
	}
	init(1, 0, n - 1);
	printf("%lld", divide(0, n - 1));


	return 0;
}