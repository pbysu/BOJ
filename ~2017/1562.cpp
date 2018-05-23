#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll dp[101][10][1 << 10];
ll mod = 1000000000;
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 9; i++) {
		dp[1][i][1 << i] = 1;
	}
	//pos : last : statue
	for (int i = 1; i <= n-1; i++) {//자리
		for (int j = 0; j < 10; j++) {//다음 들어갈 수
			for (int k = 0; k < (1 << 10); k++) {//현재 상태
				if (!dp[i][j][k]) continue;
				if (!(k&(1 << j))) continue;
				if (j +1<= 9) 
					dp[i + 1][j + 1][k | (1 << (j+1))] = (dp[i][j][k] + dp[i + 1][j + 1][k | (1 << (j+1))]) % mod;
				if (j-1 >=0)
					dp[i + 1][j - 1][k | (1 << (j-1))] = (dp[i][j][k] + dp[i + 1][j - 1][k | (1 << (j-1))]) % mod;
			}
		}
	}
	ll ret = 0;
	for (int i = 0; i < 10; i++) {
		ret = (ret + dp[n][i][(1 << 10) - 1]) % mod;
	}
	printf("%lld\n", ret);

	return 0;
}