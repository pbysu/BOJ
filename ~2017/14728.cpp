#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, t;
int table[101][2];
int dp[101][10001];

int func(int sub, int time) {
	if (sub >= n)
		return 0;
	if (time > t) return 0;
	int &ret = dp[sub][time]; 
	if (ret != 0)
		return ret;
	if (time + table[sub][0] <= t)
		ret = table[sub][1] + func(sub + 1, time + table[sub][0]);
	ret = max(ret,func( sub + 1, time));
	return ret;
}
int main() {
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &table[i][0], &table[i][1]);
	}
	printf("%d", func(0, 0));
	return 0;
}