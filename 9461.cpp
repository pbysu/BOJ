#include <algorithm>
#include <iostream>

using namespace std;
long long arr[110] = { 0,1,1,1,2,2,3,4,5,7,9 };
long long dp[110];

long long ret;
int tc;
int temp;

long long func(int pos) {

	if (dp[pos] != 0) return dp[pos];

	if (pos <= 10) { 
		dp[pos] = arr[pos];
		return arr[pos]; }

	else ret = func(pos - 1) + func(pos - 5);

	dp[pos] = ret;
	return ret;
}
int main() {


	scanf("%d", &tc);

		for (int i = 0; i < tc; i++) {
			scanf("%d", &temp);
			printf("%lld\n", func(temp));
		}

	return 0;
}