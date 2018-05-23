#define  _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#define INF 2e9
using namespace std;
typedef long long ll;
ll n, m;
vector<pair<ll, int>> v;
int seg[400010];

int query(int lo, int hi, int node, int x, int y) {
	if(hi<x || lo>y) return 0;
	if (lo <= x && y <= hi)return seg[node];
	int mid = (x + y) / 2;
	int left = query(lo, hi, node * 2, x, mid);
	int right = query(lo, hi, node * 2 + 1, mid + 1, y);
	return max(left, right);
}

int init(int node, int x, int y) {
	if (x == y) 
		return seg[node] = v[x].second;
	if (x >y) 
		return 0;
	int mid = (x + y) / 2;
	return seg[node] =
		max(init(node * 2, x, mid), init(node * 2 + 1, mid + 1, y));
}
int main() {
	scanf("%d %d", &n, &m);
	v.resize(n);
	for(int i =0; i< n; i++){
		scanf("%lld %d", &v[i].first, &v[i].second);
	}
	init(1, 0, n - 1);
	int a = 0, b = 0;
	ll sum = 0;
	int ans = INF;
	for (a = 0; a < n; a++) {
		if(a!=0)
			sum -= v[a].first;
		while (sum < m ) {
			if (b >= n)break;
			sum += v[b++].first;
		}
		if(sum >=m)
		ans = min(ans, query(a, b-1, 1, 0, n - 1));
	}
	printf("%d", ans);
	return 0;

}