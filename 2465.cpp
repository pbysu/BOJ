#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
stack<int>s;
stack<int>ans;
int num[100000];
int lank[100000];
int seg[400000];
int n;

int val;
int temp;
int update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos >y) return seg[node];

	if (x == y) return seg[node] = val;

	int mid = (x + y) >> 1;

	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node*2 + 1, mid + 1, y);
}
int query(int val, int node, int x, int y) {
	if (x == y) {
		update(x, 0, 1, 0, n - 1);
		return x;
	}
	int mid = (x + y) >> 1;
	if (val > seg[node * 2]) return query(val - seg[node * 2], node * 2 + 1, mid + 1, y);
	if (val <= seg[node * 2]) return query(val, node * 2, x, mid);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		update(i, 1, 1, 0, n-1);
	}
	sort(num, num + n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		s.push(val);
	}
	while (!s.empty()) {
		ans.push(query(s.top()+1,1,0,n-1));
		s.pop();
	}
	while (!ans.empty()) {
		printf("%d\n", num[ans.top()]);
		ans.pop();
	}


	return 0;
}