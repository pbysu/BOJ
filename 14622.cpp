#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;

bool prime[5000001];
bool check[5000001];
ll n, u, v;
ll vs, us;
ll pu[4];
ll pv[4];
int main() {
	for (ll i = 0; i < 4; i++)
		pu[i] = pv[i] = -1;
	ll lim = sqrt(5000001);
	prime[1] = prime[0] = true;
	for (ll i = 2; i <= lim; i++) {
		if (prime[i])continue;
		for (ll j = i*i; j <= 5000000; j += i) {
			prime[j] = true;
		}
	}
	scanf("%lld", &n);
	for (ll i = 0; i < n; i++) {
		scanf("%lld %lld", &u, &v);
		if (prime[u]) vs += (pv[1] != -1 ? pv[1] : 1000);
		else if (check[u]) us -= 1000;
		else check[u] = true, pu[0] = u, sort(pu, pu + 4);

		if (prime[v]) us += (pu[1] != -1 ? pu[1] : 1000);
		else if (check[v]) vs -= 1000;
		else check[v] = true, pv[0] = v, sort(pv, pv + 4);
	}
	if (vs > us)printf("소수 마스터 갓규성\n");
	else if (us > vs) printf("소수의 신 갓대웅\n");
	else printf("우열을 가릴 수 없음\n");
}