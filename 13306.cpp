#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;
vector<int> p;
int n, q;
vector<pair<int, pair<int,int>>> query;
stack<string> s;
vector<int> realParent;
int find(int pos) {
	if (p[pos] == pos)
		return pos;
	return p[pos] = find(p[pos]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	p[y] = x;
}
int main() {
	scanf("%d %d", &n, &q);
	p.resize(n+1);
	realParent.resize(n+1);
	query.resize(n + q);
	for (int i = 0; i <= n; i++) {
		p[i] = i;
	}
	
	for (int i = 2; i <= n; i++) {
		scanf("%d", &realParent[i]);
	}
	for (int i = 1; i <= n + q-1; i++) {
		scanf("%d", &query[i].first);
		if (query[i].first == 1) {
			scanf("%d %d", &query[i].second.first, &query[i].second.second);
		}
		else
			scanf("%d", &query[i].second.first);
	}

	for (int i = query.size()-1; i > 0; i--) {
		if (query[i].first == 0) {
			merge(query[i].second.first, realParent[query[i].second.first]);
		}
		else {
			if (find(p[query[i].second.first]) !=find( p[query[i].second.second])) s.push("NO");
			else s.push("YES");
		}
	}

	while (!s.empty()) {
		cout << s.top() << "\n";
		s.pop();
	}


	return 0;
}