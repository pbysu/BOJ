#include<stdio.h>
#include<algorithm>
#define INF 2000000000
using namespace std;
//배열 크기는 n의 4배
int n, m, seg[400040];
int val;
//5개 변수
// 완전 이진트리가 아니라서 정확히 구간의 어디서 어디까진지 알수 없음
// 그래서 미리 계산하지 않고 각 case 별 시작고 끝값을 매개변수로 넣어둔다.
int update(int pos, int val , int node , int x, int y) {
	//기저사례
	//1. 구간 외
	if (pos < x || y < pos) {
		return seg[node];
	}
	//2. 종착
	if (x == y) {
		return seg[node] = val;
	}

	int mid = (x + y) >> 1;
	int leftChildVal = update(pos, val, node * 2, x, mid);
	int rightChildVal = update(pos, val, node * 2 + 1,mid+1, y);
	//기저 사례를 통해서 if,else 를 줄임;

	return seg[node] = min(leftChildVal, rightChildVal);


}

int query(int low, int hig, int node, int x, int y) {
	if (y < low || hig < x) {
		return INF;
	}
	if (low <= x &&y <= hig) {
		return seg[node];
	}

	int mid = (x + y) >> 1;
	int leftChildVal = query(low, hig, node * 2, x, mid);
	int rightChildVal = query(low, hig, node * 2 + 1,mid+1, y);
	//기저 사례를 통해서 if,else 를 줄임;

	return min(leftChildVal, rightChildVal);


}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		update(i, val, 1, 0, n-1);
	}

	while (m--) {
		int lo, hi;
		scanf("%d%d", &lo, &hi);

		if (lo > hi) swap(lo, hi);

		printf("%d\n", query(lo - 1, hi - 1, 1, 0, n - 1));
	}

	return 0;
}