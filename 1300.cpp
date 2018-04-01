#include<iostream>
#include<algorithm>

using namespace std;

int n, k;

int main() {
	scanf("%d\n%d", &n, &k);
	int cnt;
	int lo = 0;
	int hi = k;
	int mid;
	while (lo < hi-1) {
		mid = (lo + hi) >> 1;
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (i > mid)
				break;
			cnt += min(n, mid / i);
		}

		if (cnt >= k) {
			hi = mid;
		}
		else
			lo = mid;
	}

	printf("%d", hi);
	return 0;
}