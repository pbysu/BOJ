#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define INF 1e9
using namespace std;
vector<vector<int>> v;
int cost, n, tmp;
int dp[21][301];
int ans[21][301];
int func(int company, int cost) {
	if (company >= n)
		if (cost <= 0)return 0;
		else return -INF;
	int &ret = dp[company][cost];
	if (ret != -1)
		return ret;
	ret = 0;

	int temp;
	for (int i = 0; i <= cost; i++) {
		temp = func(company + 1, cost - i)+v[i][company];
		if (ret < temp) {
			ret = temp;
			ans[company][cost] = cost -i;
		}
	}
	return ret;
}
int main() {
	scanf("%d %d",&cost, &n);
	v.resize(cost+1,vector<int>(n));
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= cost; i++) {
		scanf("%d", &tmp);
		for (int j = 0; j < n; j++) {
			scanf("%d", &v[i][j]);
		}
	}
	int mx = func(0, cost);
	printf("%d\n",mx);
	int tcost = cost;
	for (int i = 0; i < n; i++) {
		
		printf("%d ",tcost - ans[i][tcost]);
		tcost = ans[i][tcost];
	}

	return 0;
}