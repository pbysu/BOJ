#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;
ll lo, hi;
ll sqr, share, idx;
vector<bool> check;
int main() {
	scanf("%lld %lld", &lo, &hi);
	check.resize(hi - lo + 2);
	int root = sqrt(hi);
	for (ll i = 2; i <= root; i++) {
		sqr = i*i;
		share = lo / sqr;
		if (lo%sqr > 0) share++;
		while (hi >= share*sqr) {
			check[share*sqr - lo] = true;
			share++;
		}
	}
	int ret = 0;
	for (bool ch : check) {
		if (!ch)ret++;
	}
	printf("%d", ret-1);
	return 0;
}