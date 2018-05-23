#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int checkEdgeTc[32001];
vector<int> vInput[32001];
queue<int> qAns;

void dfs(int i) {
	
	if (checkEdgeTc[i]) {
		return;
	}

	else {
		printf("%d ", i);
		checkEdgeTc[i]--;
	}
		

	for (int j : vInput[i]) {
		--checkEdgeTc[j];
		dfs(j);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	int s, e;

	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &s, &e);
		vInput[s].push_back(e);
		checkEdgeTc[e]++;
	}
	
	for (int i = 1; i <= n; i++) {
		dfs(i);
	}

	return 0;
}