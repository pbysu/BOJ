#include<iostream>
#include<algorithm>
#include<vector>
#define INF 987654321
using namespace std;
vector<int> v;
int dp[10001];
int n, k;

int func(int num, int cnt) {
	if (num < 0)
		return INF;
	if (num == 0)
		return 0;
	int &ret = dp[num];
	if (ret != 0)
		return ret;
	int temp = INF;

	for (int i = cnt; i < n; i++) {
		temp = min(func(num - v[i], cnt), temp);
	}
	ret += temp + 1;
	return ret;
}

int main() {

	scanf("%d %d", &n, &k);
	v.resize(k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int ans = func(k, 0);
	if (ans == INF + 1)
		ans = -1;
	printf("%d", ans);

	return 0;
}