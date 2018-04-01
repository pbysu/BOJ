#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int n;
int s, e, val;
int visited[100001];
vector<vector<pair<int, int>>> v;
int lastNode;


pair<int, int> findLastNode(int s) {
	pair<int, int> temp;
	int ret = 0 , tlast, last=s;
	visited[s] = true;
	int MAX = 0;
	bool jd = true;
	for (int i = 0; i < v[s].size(); i++) {

		if (!visited[v[s][i].first]) {
			visited[v[s][i].first] = true;
			temp = findLastNode(v[s][i].first);
			ret = temp.second + v[s][i].second;
			tlast = temp.first;

			if (MAX < ret) {
				last = tlast;
				MAX = ret;
			}
		}
	}

	return{ last, MAX };
}


int func(int pos) {
	int ret = 0;

	if (visited[pos])
		return ret;

	for (int i = 0; i < v[pos].size(); i++) {
		if (!visited[v[pos][i].first]) {
			ret = max(ret, func(v[pos][i].first) + v[pos][i].second);
		}
	}

	return ret;
}


int main() {
	scanf("%d", &n);
	v.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &s);
		scanf("%d", &e);
		while (e != -1) {
			scanf("%d", &val);
			v[s].push_back({ e,val });
			scanf("%d", &e);
		}
	}

	lastNode = findLastNode(1).first;
	memset(visited, false, sizeof(visited));

	
	printf("%d", findLastNode(lastNode).second);
	return 0;
}