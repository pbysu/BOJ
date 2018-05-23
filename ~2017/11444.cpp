#include<cstdio>
#include<algorithm>
#define mod 1000000007
using namespace std;
typedef  long long ll;

ll n;
ll T[2][2] = { {1,1},{1,0} };
ll B[2][2] = { { 1,0 },{ 0,1 } };
ll ret[2][2];
ll f[2][2] = { { 1,1 },{ 1,0 } };

void matrixMul(ll f[][2], ll s[][2]) {

	ll temp;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ret[i][j] = ((f[i][0] * s[j][0]) % mod + (f[i][1] * s[j][1]) % mod) % mod;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			f[i][j] = ret[i][j];
		}
	}
	return;
}
int main() {
	scanf("%lld", &n);
	if (n <= 2) {
		printf("1\n");
		return 0;
	}
	n -= 2;
	while (n > 0) {
		if (n & 1) {
			matrixMul(B, T);
			n--;
		}
		else {
			matrixMul(T, T);
			n /= 2;
		}
	}
	matrixMul(f,B);
	printf("%lld\n", f[0][0]);
	return 0;
}