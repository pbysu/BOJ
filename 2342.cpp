#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 500004

using namespace std;

int input[100002];
int dp[100002][5][5];

void func(int n) {
	int a = input[n];
	int temp;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			
			if (dp[n - 1][i][j] < INF) {

				if (a != i) {
					if (j == 0) {
						temp = 0;
					}

					else {
						temp = abs(j - a);

						if (temp != 2) {
							if (temp == 0)
								temp = -1;
							else
								temp = 1;
						}
					}
					dp[n][i][a] = min(dp[n - 1][i][j] + temp + 2, dp[n][i][a]);
				}
				
				if (a != j) {

					if (i == 0) {
						temp = 0;
					}

					else {
						temp = abs(i - a);

						if (temp != 2) {
							if (temp == 0)
								temp = -1;
							else
								temp = 1;
						}
					}

					dp[n][a][j] =min( dp[n - 1][i][j] + temp + 2, dp[n][a][j]);
				}
			}
		}
	}
}




int main() {
	int c = 1;
	memset(dp, 0x7f, sizeof(dp));

	while (true) {
		scanf("%d", &input[c]);
		if (input[c] == 0)	 break;
		c++;
	}

	dp[0][0][0] = 0;

	for (int i = 1; i < c; i++) {
		func(i);
	}

	int ans = 987654321;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ans = min(dp[c - 1][i][j], ans);
		}
	}
	printf("%d", ans);

	return 0;
}