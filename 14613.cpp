#include<iostream>
#include<algorithm>
#include<vector>
#define win 50
#define lose -50
#define draw 0
using namespace std;
double w, l, d;
double cur = 2000;
double dp[21][21][21];
double ans[5];

int main() {
	scanf("%lf %lf%lf", &w, &l, &d);
	dp[0][0][0] = 1;

	for (int i = 1; i <= 20; i++) {
		for (int x = 0; x <= i; x++) {
			for (int y = 0; y + x <= i; y++) {
				int z = i - y - x;
					if (!x && !y && !z) continue;
					dp[x][y][z] += (x > 0 ? dp[x - 1][y][z] * w : 0)
						+ (y > 0 ? dp[x][y - 1][z] * d : 0) +
						(z > 0 ? dp[x][y][z - 1] * l : 0);
				
			}
		}
	}

	for (int x = 0; x <= 20; x++) {
		for (int y = 0; y + x <= 20; y++) {
			int z = 20 - x - y;
			if (x + y + z == 0) continue;
			int score =2000+ x*win + y*draw + z*lose;
			if (score >= 1000 && score <= 1499) {
				ans[0] += dp[x][y][z];
			}
			else if (score >= 1500 && score < 2000) {
				ans[1] += dp[x][y][z];
			}
			else if (score >= 2000 && score < 2500) {
				ans[2] += dp[x][y][z];
			}
			else if (score >= 2500 && score < 3000) {
				ans[3] += dp[x][y][z];
			}
			else if (score >= 3000 && score < 3500) {
				ans[4] += dp[x][y][z];
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		printf("%.8lf\n", ans[i]);
	}
	return 0;
}