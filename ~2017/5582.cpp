#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char str[4001];
char str1[4001];
int dp[4001][4001];
int ans = 0;
int main() {
	scanf("%s", &str);
	scanf("%s", &str1);

	for (int i = 0; i < strlen(str); i++) {
		for (int j = 0; j < strlen(str1); j++) {
			if (str[i] == str1[j]) {
				if (i*j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i-1][j - 1] + 1;

				ans = max(dp[i][j], ans);
			}
		}
	}
	printf("%d", ans);

	return 0;
}