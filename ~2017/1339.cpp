#include<iostream>
#include<algorithm>
#include<cstring>
#include<functional>
using namespace std;
int n;
typedef unsigned long long ll;
char str[10][10];
ll alpa[26];
int check[26];
ll po;
int main() {
	scanf("%d", &n);
	memset(check, -1, sizeof(check));
	for (int i = 0; i < n; i ++ ) {
		scanf("%s", &str[i]);
		reverse(str[i], str[i] + strlen(str[i]));
		po = 1;
		for (int j = 0; j < strlen(str[i]); j++) {
			alpa[str[i][j]-'A'] += po ;
			po *= 100;
		}
	}
	sort(alpa, alpa + 26, greater<ll>());
	ll ans = 0;
	ll k = 9;
	po = 1;
	for (int i = 0; i < 26; i++) {
		po = 1;
		while (alpa[i] > 0) {
			ans += alpa[i] % 100 * k*po;
			alpa[i] /= 100;
			po *= 10;
		}
		k--;
	}
	printf("%lld", ans);
	return 0;
}