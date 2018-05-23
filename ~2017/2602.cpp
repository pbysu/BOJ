#include<iostream>
#include<cstring>

using namespace std;
char doru[21];
char dol[2][101];
int dp[21][102];
int dp1[21][102];

int main() {
	scanf("%s", doru);
	scanf("%s", dol[0]);
	scanf("%s", dol[1]);
	if (dol[0][0] == doru[0])
		dp[0][0] = 1;

	if (dol[1][0] == doru[0])
		dp1[0][0] = 1;
	int cnt = 0;
	int cnt1 = 0;

	for (int i = 0; i < strlen(dol[0]); i++) {

		if (doru[0] == dol[0][i]) {
			cnt++;
			dp[0][i] = cnt;
		}
		else
			dp[0][i] = cnt;

		if (doru[0] == dol[1][i]) {
			cnt1++;
			dp1[0][i] = cnt1;
		}
		else
			dp1[0][i] = cnt1;
	}
	

	for (int k = 1; k < strlen(doru); k++) {
		if (k % 2 == 0) {
			
			for (int i = 1; i < strlen(dol[0]); i++) {
				if (doru[k] == dol[0][i] && dp[k - 1][i - 1] != 0) {
					dp[k][i] = dp[k - 1][i - 1] + dp[k][i-1];
				}
				else
					dp[k][i] = dp[k][i - 1];

				if (doru[k] == dol[1][i] && dp1[k - 1][i - 1] != 0) {
					dp1[k][i] = dp1[k-1][i - 1] + dp1[k][i-1];
				}
				else
					dp1[k][i] = dp1[k][i - 1];
			}
		}
		else {
			for (int i = 0; i < strlen(dol[1]); i++) {
				if (doru[k] == dol[1][i] && dp[k-1][i-1]!=0) {
					cnt++;
					dp[k][i] = dp[k - 1][i - 1] + dp[k][i - 1];
				}
				else
					dp[k][i] = dp[k][i - 1];


				if (doru[k] == dol[0][i] && dp1[k - 1][i - 1] != 0) {
					cnt1++;
					dp1[k][i] = dp1[k - 1][i - 1] + dp1[k][i - 1];
				}
				else
					dp1[k][i] = dp1[k][i - 1];
			}
		}
	}

	printf("%d", dp1[strlen(doru) - 1][strlen(dol[0]) - 1]
		+ dp[strlen(doru) - 1][strlen(dol[0]) - 1]);

	return 0;
}