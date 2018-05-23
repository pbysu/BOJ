#include <iostream>
using namespace std;

const int mod = 1000000;
const int p = mod / 10 * 15;
int dp[p] = { 0,1 };
int main() {
	long long n;
	cin >> n;
	for (int i = 2; i<p; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= mod;
	}
	cout << dp[n%p] << '\n';
	return 0;
}