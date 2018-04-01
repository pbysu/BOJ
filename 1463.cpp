#include<iostream>
#include<algorithm>
#define INF 987654321

using namespace std;

int dp[1000001];

void func(int x , int tc) {
	if (x < 1)
		return;
	int &ret = dp[x];
	if (ret == 0) {
		ret = INF;
	}

	if (ret <= tc)
		return;

	ret = tc;
	if (!(x % 3)) {
		func(x/3, 1+tc);
	}

	if (!(x % 2)) {
		func(x / 2, 1+tc);
	}
	func(x-1, 1+tc);
}

int main() {
	int tmp;
	scanf("%d", &tmp);

	func(tmp, 0);
	printf("%d", dp[1]);

	return 0;
}