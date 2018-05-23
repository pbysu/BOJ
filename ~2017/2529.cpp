#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n;
char x;
int in[15];
int lowIn[15];
int ans[15];
int lowAns[15];
vector<vector<int>> adj;
int idx;
int lowIdx;
int main() {
	scanf("%d", &n);
	adj.resize(n + 2);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c", &x);
		if (x == '<') {
			adj[i + 1].push_back(i);
			in[i]++;
			lowIn[i]++;
		}
		else {
			adj[i].push_back(i + 1);
			in[i + 1] ++;
			lowIn[i+1]++;
		}
	}
	int num = 9;
	int lnum = n;
	while (lnum >= 0) {
		for (int i = 0; i <= n; i++) {
			if (in[i] == 0) {
				in[i] = -1;
				idx = i;
				break;
			}
		}
		for (int i = n; i >= 0; i--) {
			if (lowIn[i] == 0) {
				lowIn[i] = -1;
				lowIdx = i;
				break;
			}
		}
		for (int next : adj[idx]) {
			in[next]--;
		}
		for (int next : adj[lowIdx]) {
			lowIn[next]--;
		}
		ans[idx] = num;
		lowAns[lowIdx] = lnum;
		lnum--;
		num--;
	}
	for (int i = 0; i <= n; i++) {
		printf("%d", ans[i]);
	}
	printf("\n");
	for (int i = 0; i <= n; i++) {
		printf("%d", lowAns[i]);
	}
	printf("\n");
	return 0;
}