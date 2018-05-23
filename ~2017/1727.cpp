#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

#define INF 987654321
using namespace std;
int n, m;
vector<int> big;
vector<int>small;
int dp[1001][1001];
int func(int a, int b) {
	if (b == small.size())
		return 0;
	if (a ==big.size())
		return INF;

	int &ret = dp[a][b];
	if (ret != -1) return ret;
	ret = 0;
	ret = func(a + 1, b + 1) + abs(big[a] - small[b]);
	ret = min(ret,func(a+1, b));
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	big.resize(n);
	small.resize(m);
	for (int i = 0; i < n; i++)scanf("%d", &big[i]);
	for (int i = 0; i < m; i++)scanf("%d", &small[i]);
	sort(big.begin(), big.end());
	sort(small.begin(), small.end());
	if (big.size() < small.size()) swap(big, small);
	memset(dp, -1, sizeof(dp));
	printf("%d", func(0, 0));


	return 0;
}