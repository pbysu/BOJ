#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define INF 1e9;
using namespace std;
typedef long long ll;
int n, m;
vector<ll> input;
int main() {
	scanf("%d %d", &n, &m);
	input.resize(n);
	for (int tmp, i = 0; i< n; i++) {
		scanf("%d", &tmp);
		input[i]= tmp;
	}
	ll left = 0;
	ll right = INF;
	ll mid;
	ll ans = 0;
	ll sum;

	while (left <= right) {
		mid = (left + right) >> 1;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (input[i] > mid) sum += input[i] - mid;
		}
		if (sum >= m) {
			if (ans < mid) {
				ans = mid;
			}
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}