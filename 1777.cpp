#include <iostream>
#include <algorithm>
#include <stack>	
using namespace std;
stack <int> s;
stack <int> sAns;
int num[100001];
int seg[400000];
int val, n;

int update(int pos, int val, int node, int x, int y) {
	if (x > pos || y < pos) return seg[node];
	if (x == y) return  seg[node] = val;

	int mid = (x + y) >> 1;

	return seg[node] = update(pos, val, node * 2, x, mid)
		+ update(pos, val, node * 2 + 1, mid + 1, y);
}

int query( int val, int node, int x, int y) {
	if (x == y) {
		update(x, 0, 1, 0, n - 1);
		return x+1;
	}

	int mid = (x + y) >> 1;
	if (seg[node * 2 + 1] < val)
		return query(val - seg[node * 2 + 1], node * 2, x, mid);
	else 
		return query(val, node * 2 + 1, mid + 1, y);
}

int main() {
	scanf("%d", &n);
	for (int i=0; i < n; i++) {
		update(i, 1, 1, 0, n - 1);
		scanf("%d", &val);
		s.push(val);
	}

	for (int i = 0; i < n; i++) {
		sAns.push(query(s.top()+1, 1, 0, n - 1));
		
		s.pop();
	}
	int temp = 1;
	while (!sAns.empty()) {
		num[sAns.top()] = temp;
		temp++;
		sAns.pop();
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", num[i + 1]);
	}

	return 0;
}