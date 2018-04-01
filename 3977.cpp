#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#define MAX 100001
using namespace std;
int t, n, m, from, to;
stack<int> s;
int cnt;
bool finished[MAX];
int dfsn[MAX], indegree[MAX], sCnt[MAX], sccCnt;

vector<vector<int>> edge, allScc;

int sccDfs(int pos) {
	dfsn[pos] = ++cnt;
	int ret = dfsn[pos];
	s.push(pos);

	int next;
	for (int i = 0; i < edge[pos].size(); i++) {
		next = edge[pos][i];
		if (dfsn[next] == 0)ret = min(ret, sccDfs(next));
		else if (!finished[next]) ret = min(dfsn[next], ret);
	}

	if (ret == dfsn[pos]) {
		vector<int> v;
		int temp;
		while (true) {
			temp = s.top();
			s.pop();
			finished[temp] = true;
			sCnt[temp] = sccCnt;
			v.push_back(temp);
			if (temp == pos)break;
		}
		sort(v.begin(), v.end());
		allScc.push_back(v);
		sccCnt++;
	}
	return ret;
}


int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		edge.clear();
		allScc.clear();
		edge.resize(n);
		memset(sCnt, -1, sizeof(sCnt));
		memset(dfsn, 0, sizeof(dfsn));
		memset(finished, 0, sizeof(finished));

		for (int i = 0; i < m; i++) {
			scanf("%d %d", &from, &to);
			edge[from].push_back(to);
		}
		sccCnt = 0; cnt = 0;
		for (int i = 0; i < n; i++) {
			if (dfsn[i] == 0) sccDfs(i);
		}
		
		
		vector<int> indegree;
		indegree.resize(sccCnt,0);

		for (int i = 0; i < n; i++) {
			for (int j= 0 ; j < edge[i].size(); j++) {
				int next = edge[i][j];
				if (sCnt[i] != sCnt[next]) indegree[sCnt[next]]++;
			}
		}
		int ret = 0;
		int idx;
		for (int i = 0; i < sccCnt; i++) {
			if (indegree[i] == 0) { ret++; idx = i; }
		}
		if (ret > 1)
			printf("Confused\n");
		else {
			for (int i = 0; i<allScc[idx].size(); i++) {
				printf("%d\n", allScc[idx][i]);
			}
		}
		printf("\n");
	}
	return 0;
}