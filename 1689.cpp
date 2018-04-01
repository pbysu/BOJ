#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int>> so;
int n;
int main() {
	scanf("%d", &n);
	so.resize(n * 2);
	for (int u, v, k = 0, i = 0; i < n; i++, k += 2) {
		scanf("%d %d", &u, &v);
		so[i] = { u,1 };
		so[n+ i] = { v,-1 };
	}
	sort(so.begin(), so.end());;

	int cnt = 0;
	int ans = 0;
	for (int i = 0; i <so.size(); i++) {
		cnt += so[i].second;
		ans = max(cnt, ans);
	}
	printf("%d", ans);
	return 0;
}