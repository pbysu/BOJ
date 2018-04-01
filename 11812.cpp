#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int  k,q;
typedef long long ll;
ll n;
ll len, u, v;
int main() {
	scanf("%lld %d %d", &n, &k, &q);
	for (int  i = 0; i < q; i++) {
		scanf("%lld %lld", &u, &v);
		len = 0;
		if (k == 1) {
			printf("%lld\n", abs(u - v));
		}
		else {
			while (u != v) {

				while (u > v) {
					u = (u + k - 2) / k;
					len++;
				}

				while (u < v) {
					v = (v + k - 2) / k;
					len++;
				}
			}
			printf("%lld\n", len);
		}
	
	}
	return 0;
}