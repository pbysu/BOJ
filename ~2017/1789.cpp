#include <cstdio>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;
ull n;
int main() {
	scanf("%llu", &n);
	ull left = 0;
	ull right = n;
	ull mid = 0;
	while (left <= right) {
		mid = (left + right) >> 1;
		ull tmp = (mid + 1)*(mid) / 2;
		if (tmp+mid >= n) {
			right = mid-1;
		}
		else {
			left = mid+1;
		}
	}

	printf("%llu\n", left);

	return 0;
}