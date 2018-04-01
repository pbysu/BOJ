#include <iostream>
#define must 9901
using namespace std;
int map[1001][1001];
int dp[3][100001];
int n, m;
int siz;

int main() {
	scanf("%d", &n);
	siz = n-1 ;

	dp[0][0] = dp[0][1] = 1;
	dp[1][0] = dp[1][1] = 1;
	dp[2][0] = dp[2][1] = 1;
	int temp = 1;

	for (int i = 1; i <= siz; i++) {

		dp[0][i] = ((dp[1][i-1] + dp[0][i-1])%must + dp[2][i-1])%must;
		dp[1][i] = (dp[0][i-1] + dp[2][i-1])%must;
		dp[2][i] = (dp[0][i-1] + dp[1][i-1])%must;
	}

	printf("%d", ((dp[1][siz] + dp[0][siz]) % must + dp[2][siz]) % must);

	return 0;
}