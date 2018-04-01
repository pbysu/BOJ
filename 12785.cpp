#include<iostream>
#include<algorithm>

using namespace std;
int n[202][202];
int x = 1000007;
int main() {
	for (int i = 1; i < 202; i++) {
		n[0][i] = 1;
		n[i][0] = 1;
	}
	for (int i = 1; i < 202; i++) {
		for (int j = 1; j < 202; j++) {
			n[i][j] = (n[i - 1][j] + n[i][j - 1])%x;
		}
	}
	int a, b;
	int p, q;
	scanf("%d %d\n%d %d", &p, &q, &a, &b);
	long long ans1 = n[a - 1][b - 1];
	if (ans1 == 0) ans1 = 1;
	long long ans2 = n[p - a][q - b];
	if (ans2 == 0)ans2 = 1;
	ans1 = (ans1 * ans2) % x;
	printf("%lld", ans1);
		
}