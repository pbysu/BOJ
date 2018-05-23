#include<iostream>
#include<algorithm>
using namespace std;

int dp[20];

int func(int n, int cnt) {

	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
	int &ret = dp[n];

	if (ret != 0)
		return ret;
	ret = func(n - 3, cnt + 1);
	ret += func(n - 2, cnt + 1);
	ret += func(n - 1, cnt + 1);

	return ret;
}

int main() {
	int t, n;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", func(n,0));

	}
	return 0;
}