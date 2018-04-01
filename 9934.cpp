#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
int n;
vector<int> in;
queue<pair<int, int>>q;
int main() {
	scanf("%d", &n);
	int left = 0;
	int right = pow(2, n) - 2, mid;
	in.resize(right + 1);
	for (int i = 0; i <= right; i++) {
		scanf("%d", &in[i]);
	}
	q.push({ left,right });
	int lo, hi;
	int two = 1;
	int k = 0;
	while (!q.empty()) {
		lo = q.front().first;
		hi = q.front().second;
		mid = (lo + hi) >> 1;
		printf("%d ", in[mid]);
		if (++k == two) {
			printf("\n");
			two *= 2;
			k = 0;
		}
		q.pop();
		if (lo <= mid - 1) {
			q.push({ lo,mid - 1 });
			q.push({ mid + 1, hi });
		}
	}
	return 0;
}