#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int n;
ll dp[91];

ll func(int cas) {

	ll &ret = dp[cas];

	if (dp[cas] != 0)
		return ret;

	return ret =  func(cas - 1) + func(cas - 2);

}

int main() {
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 1;

	printf("%lld", func(n));

	return 0;
}