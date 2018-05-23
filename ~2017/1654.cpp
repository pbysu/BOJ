#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll input[10001];
ll left, right = 0, mid, sum, ans = 0;
ll k, n;
int main() {
	scanf("%lld %lld", &k, &n);

	for (int i = 0; i < k; i++) {
		scanf("%lld", &input[i]);
		right = max(right, input[i]);
	}
	left = 0;
	while (left < right) {
		mid = (left + right+1) >> 1;
		sum = 0;
		for (int i = 0; i < k; i++) {
			sum += input[i] / mid;
		}

		if (sum >= n) {
			left = mid;
		}
		else
			right = mid-1;

	}
	printf("%lld", left);
	return 0;
}