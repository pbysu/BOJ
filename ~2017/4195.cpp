#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;


pair<int, int> uf[100000];

int find(int pos) {
	if (uf[pos].first < 0) return pos;
	else find(uf[pos].first);
}

int merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return uf[a].second;

	uf[a].second += uf[b].second;
	uf[b].first = a;
	
	return uf[a].second;
}

int main() {
	int f;
	scanf("%d", &f);
	int n;
	char u[20], v[20];
	while (f--) {
		scanf("%d", &n);
		int m = 2 * n;
		if (m >= 100000) m = 100000;
		for (int i = 0; i < m; i++) {
			uf[i].first = -1;
			uf[i].second = 1;
		}
		vector<string> name;
		vector<pair<string, string>> save;
	
		for (int i = 0; i < n; i++) {
			cin >> u >> v;
			save.push_back({ u,v });
			name.push_back(u);
			name.push_back(v);
		}
		sort(name.begin(), name.end());
		vector<string>::iterator name_it = unique(name.begin(), name.end());
		name.resize(distance(name.begin(), name_it));

		for (int i = 0; i < n; i++) {
			string x = save[i].first;
			string y = save[i].second;

			int v = lower_bound(name.begin(), name.end(), x) - name.begin();
			int u = lower_bound(name.begin(), name.end(), y) - name.begin();

			printf("%d\n", merge(v, u));
		}



	}
	return 0;
}