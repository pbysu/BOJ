#include<iostream>
#include<algorithm>
#include<vector>
#define INF 987654321
using namespace std;
int t, n, m;
vector<pair<int, int>> vp;
vector<vector<double>> dp;
double len(pair<int, int> p, pair<int, int> q) {
	return sqrt((p.first - q.first)*(p.first - q.first) + (p.second - q.second)*(p.second - q.second));
}
double func(int go, int back) {
	if (go == n - 1 && back == n - 1)
		return 0;
	if (go == n - 1) return len(vp[back], vp[n-1]);
	if (back == n - 1)  return  len(vp[go], vp[n - 1]);

	double &ret = dp[go][back];
	if (ret != -1)return ret;
	ret = INF;
	int next = max(go, back) + 1;
	ret = min(ret, func(back, next) + len(vp[go], vp[next]));
	ret = min(ret, func(next, go) + len(vp[back], vp[next]));
	return ret;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		dp.clear();
		scanf("%d", &n);
		dp.resize(n, vector<double>(n, -1));
		vp.resize(n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &vp[i].first, &vp[i].second);
		}
		printf("%.4lf\n", func(0, 0));
	}


	return 0;
}