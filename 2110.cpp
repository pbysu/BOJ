#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll input[200001];
ll left, right = 1000000001, mid, sum, ans = 0, n,c;

int check(int mid) {
	ll ex = input[0];
	int ret = 1;
	for (int i = 0; i < n; i++) {
		if (input[i] - ex >= mid) {
			ret++;
			ex = input[i];
		}
	}
	return ret;
}
int main() {
	scanf("%lld %lld", &n, &c);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &input[i]);
	}
	sort(input, input + n);

	while (left < right) {
		mid = (left + right+1) >> 1;

		int tmp = check(mid);
		if (tmp >= c) {
			left = mid;
		}
		else {
			right = mid-1;
		}
	}
	printf("%lld\n", left);

	return 0;
}