#include<iostream>
#include<algorithm>
#include<vector>
#define INF 987654321
using namespace std;
int n, k, tc;
int q, a, b;
int seg[400000][2];
int position[100000];
pair<int, int> temp;

pair<int, int> update(int pos, int val, int node, int x, int y) {
	if (x > pos || y < pos) return{ seg[node][0], seg[node][1] };
	if (x == y) {
		seg[node][0] = val;
		seg[node][1] = val;
		return{ seg[node][0], seg[node][1] };
	}

	int mid = (x + y) >> 1;

	pair<int, int> left = update(pos, val, node*2, x, mid);
	pair<int, int>right = update(pos, val, node * 2 + 1, mid + 1, y);

	seg[node][0] = min(left.first, right.first);
	seg[node][1] = max(left.second, right.second);
	return{seg[node][0] ,seg[node][1] };
}

pair<int,int> query(int low, int hi,int node, int x, int y) {
	if (x > hi || low > y) return{ INF, -INF };
	if (low <= x&&y <= hi)return{ seg[node][0],seg[node][1] };
	int mid = (x + y) >> 1;

	pair<int, int> left =query(low, hi, node * 2, x, mid);
	pair<int, int>right = query(low, hi, node * 2 + 1, mid + 1, y);

	return{ min(left.first,right.first),max(left.second,right.second) };
	
}
int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i < 4*n; i++) {
			seg[i][0] = INF;
			seg[i][1] = -INF;
			position[i] = i;
		}
		for (int i = 0; i < n; i++) {
			update(i, i , 1, 0, n - 1);
		}
		while(k--) {
			scanf("%d %d %d", &q, &a, &b);
			if (q == 0) {
				
				update(position[a], b, 1, 0, n - 1);
				update(position[b], a, 1, 0, n - 1);
				swap(position[a], position[b]);
			}
			else {
				temp = query(a , b , 1, 0, n - 1);
				if (temp.first< a || temp.second > b) printf("NO\n");
				else printf("YES\n");
			}
		}
	}
	return 0;
}