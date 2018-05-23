#include<iostream>
#include<algorithm>
#include<vector>	

using namespace std;


vector<pair<int, int>> pInput;
int input[1000000];
int seg[4000000];

int update(int pos, int val,int node, int x, int y) {
	if (pos<x || pos >y) return seg[node];
	if (x == y) return seg[node] = val;

	int mid = (x + y) >> 1;

	int left = update(pos, val, node * 2, x, mid);
	int right = update(pos, val, node*2+1, mid + 1, y);

	return seg[node] = max(left, right);
}

int query(int lo, int hig, int node, int x, int y) {
	if (lo > y || hig < x) return 0;
	if (y <= hig && lo <= x) return seg[node];

	int mid = (x + y) >> 1;

	int left = query(lo, hig, node * 2, x, mid);
	int right = query(lo, hig, node * 2 + 1, mid + 1, y);

	return max(left, right);
}

int main() {

	int n;
	scanf("%d", &n);



	pInput.resize(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
		pInput[i].first = input[i];
		pInput[i].second = i;
	}

	sort(pInput.begin(), pInput.end(), [](pair<int, int>p, pair<int, int>q){
		if (p.first != q.first) {
			return p.first < q.first;
		}
		else {
			return p.second > q.second;
		}
	});

	n = pInput.size();
	int idx;
	int maxTmp;
	for (int i = 0; i < n; i++) {
		idx = pInput[i].second;
		maxTmp = query(0, idx, 1, 0, n - 1) + 1;
		update(idx, maxTmp, 1, 0, n - 1);
	}

	printf("%d", seg[1]);

	return 0;
}