#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 1e9
using namespace std;

int dp[101][101];
int dp1[101][101];

int n, in[101];
int func1(int s, int e);

int func(int s, int e) {
	int &ret = dp[s][e];
	if (ret != -200)	 return ret;
	ret = 0;
	int left = (s - 1+n)%n!=e ? func1((s - 1 + n) % n, e) + in[(s - 1 + n) % n] :-101;
	int right = (e + 1)%n !=s ? func1(s, (e + 1) % n) + in[(e + 1) % n] : -101;
	ret -= max(left, right);
	ret = ret == 101 ? 0 : ret;
	return ret;
}

int func1(int s, int e) {
	int &ret = dp1[s][e];
	if (ret != -200)	 return ret;
	ret = 0;
	int left = (s - 1 + n) % n != e ? func((s - 1 + n) % n, e) + in[(s - 1 + n) % n] : -101;
	int right = (e + 1) % n != s ? func(s, (e + 1) % n) + in[(e + 1) % n] : -101;
	ret -= max(left, right);
	ret = ret == 101 ? 0 : ret;
	return ret;
}

int main(){
	for (int i = 0; i <= 101; i++) {
		for (int j = 0; j <= 101; j++) {
			dp[i][j] = -200;
			dp1[i][j] = -200;
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
		in[i] %= 2;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (func(i, i)+in[i] > 0) 
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}