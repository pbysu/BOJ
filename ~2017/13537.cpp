#include<cstdio>
#include<cstring>
#include<vector>	
#include<algorithm>
#define N 100000
using namespace std;
int n, tmp, m, lo, hi, val, arr[N];
vector<int> seg[4 * N];

vector<int> init(int node, int x, int y) {
	if (x > y)return seg[node];
	if (x == y)
	{
		seg[node].push_back(arr[x]); return seg[node];
	}
	int mid = (x + y) >> 1;
	vector<int> left = init(node * 2, x, mid);
	vector<int> right = init(node * 2 + 1, mid + 1,y);
	seg[node].resize(left.size() + right.size());
	merge(left.begin(), left.end(), right.begin(), right.end(), seg[node].begin());
	return seg[node];
}

int query(int lo, int hi,int val, int node, int x, int y) {
	if (lo > y || hi < x) return 0;
	if (lo <= x && y <= hi)
		return y-x+1-(upper_bound(seg[node].begin(), seg[node].end(), val)- seg[node].begin());
	int mid = (x + y) >> 1;
	int right = query(lo, hi,val, node * 2, x, mid);
	int left = query(lo, hi,val, node * 2 + 1, mid + 1, y);
	return right + left;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	init(1, 0, n - 1);

	scanf("%d", &m);
	while (m--) {
		scanf("%d %d %d", &lo, &hi, &val);
		lo--; hi--;
		printf("%d\n", query(lo, hi, val, 1, 0, n - 1));
	}
	return 0;
}