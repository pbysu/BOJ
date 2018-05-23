#include<map>
#include<cstdio>
#include<vector>
using namespace std;
int n, m, tmp;
map<int, bool> ma;
vector<int> ans;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		ma.insert({ tmp, true });
	}
	map<int, bool>::iterator it;
	for (int i = 0; i < m; i++) {
		scanf("%d", &tmp);
		it = ma.find(tmp);
		if (it != ma.end()) {
			it->second = false;
		}
	}

	int cnt = 0;

	for (it = ma.begin(); it != ma.end(); it++) {
		if (it->second)
			cnt++, ans.push_back(it->first);
	}

	if (!cnt) {
		printf("0");
	}
	else {
		printf("%d\n", cnt);
		for (int i = 0; i < ans.size(); i++) {
			printf("%d ", ans[i]);
		}
	}
		return 0;
}