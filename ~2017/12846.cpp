#include<iostream>
#include<algorithm>
#include<vector>	
#define INF 987654321
using namespace std;
typedef pair<int, int> pii;
vector<pair<int, int>> seg;
vector<int>in;
int n;
pii init(int node,int x, int y) {
	if (x == y) {
		return{ seg[node].first = in[x], seg[node].second = x };
	} 
	int mid = (x + y) >> 1;
	pii left = init(node * 2, x, mid);
	pii right = init(node * 2+1, mid + 1, y);
	if (left.first < right.first)
		return seg[node] = left;
	else
		return seg[node] = right;
}

pii query(int lo, int hi, int node, int x, int y) {
	if (lo > y || hi < x) return{ INF, INF };
	if (lo <= x && y <= hi) return seg[node];
	int mid = (x + y) >> 1;
	pii right = query(lo, hi, node * 2 + 1, mid + 1, y);
	pii left = query(lo, hi, node * 2, x, mid);
	if (right.first <= left.first)
		return right;
	else
		return left;
}

int dividConquer(int x, int y) {
	if (x > y || y < x) return 0;
	pii minPos = query(x, y, 1, 0, n - 1);
	int pos = minPos.first*(y - x + 1);
	int left = dividConquer(x, minPos.second - 1);
	int right = dividConquer(minPos.second + 1, y);
	return max(pos, max(left, right));
}
int main() {
	scanf("%d", &n);
	seg.resize(n * 4);
	in.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &in[i]);
	init(1, 0, n - 1);
	printf("%d", dividConquer(0, n - 1));

	return 0;
}