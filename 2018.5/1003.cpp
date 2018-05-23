#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef unsigned long long ull;

pair<ull,ull> dp[92];
typedef pair<ull, ull> puu;
int n;
pair<ull,ull> func(int n) {
	if (n == 0)
		return{ 1,0 };
	if (n == 1)
		return{ 0,1 };
	pair<ull,ull> &ret = dp[n];
	if (dp[n].first!=0 || dp[n].second!=0)
		return ret;
	puu a = func(n - 1);
	puu b = func(n - 2);
	return ret = { a.first + b.first, a.second + b.second };
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
	scanf("%d", &n);
	puu a = func(n);
	printf("%llu %llu\n", a.first, a.second	);
	}


	return 0;
}