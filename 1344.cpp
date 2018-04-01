#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

double p, q;
double dp[20][20];
int prime[] = { 0,1,4,6,8,9,10,12,14,15,16,18 };
double binomial() {
	double pret = 0;
	double qret = 0;
	for (int i = 0; i < 12; i++) {
		pret += dp[18][prime[i]] * pow(p, prime[i])*pow(1-p, 18 - prime[i]);
		qret += dp[18][prime[i]] * pow(q, prime[i])*pow(1-q, 18 - prime[i]);
	}
	return pret*qret;
}
int main() {
	scanf("%lf", &p); scanf("%lf", &q);
	p /= 100.0;
	q /= 100.0;
	for (int i = 0; i <= 18; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	printf("%lf", 1 - binomial());

	return 0;
}